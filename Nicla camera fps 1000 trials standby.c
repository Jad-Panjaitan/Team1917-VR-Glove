#include "sensor.h"
#include "stdio.h" // For printf
#include "pyb.h"   // For timing functions

int main() {
    // Initialize the camera
    sensor_reset();
    sensor_set_pixformat(sensor_RGB565);
    sensor_set_framesize(sensor_QVGA);
    sensor_skip_frames(2000); // Allow the camera to stabilize

    // Number of trials
    int num_trials = 1000;
    int total_frame_time = 0;

    // Capture frames and print frame rate for each trial
    for (int trial = 0; trial < num_trials; trial++) {
        uint32_t start_time = pyb_ticks_ms();
        sensor_snapshot(); // Capture a frame
        pyb_delay(1);      // Add a delay of 1ms
        uint32_t end_time = pyb_ticks_ms();

        int frame_time = end_time - start_time;
        float frame_rate = 1000.0f / frame_time;

        // Print frame rate for each trial
        printf("Trial %d: %.2f FPS\n", trial + 1, frame_rate);

        total_frame_time += frame_time;
    }

    // Calculate average frame rate
    float average_frame_time = (float)total_frame_time / num_trials;
    float average_frame_rate = 1000.0f / average_frame_time;

    // Print the average frame rate
    printf("\nAverage Frame Rate: %.2f FPS\n", average_frame_rate);

    return 0;
}
