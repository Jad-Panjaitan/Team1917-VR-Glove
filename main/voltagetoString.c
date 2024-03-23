
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "soc/soc_caps.h"
#include "esp_log.h"
#include "esp_adc/adc_oneshot.h"
#include "esp_adc/adc_cali.h"
#include "esp_adc/adc_cali_scheme.h"
#include "voltagetoString.h"


// "A"  whole thumb curl (default curl value for thumb joints) - scalar
// "B"  whole index curl (default curl value for index joints) - scalar
// "C"  whole middle curl (default curl value for middle joints) - scalar
// "D"  whole ring curl (default curl value for ring joints) - scalar
// "E"  whole pinky curl (default curl value for pinky joints) - scalar

// "(AAA)" thumb joint 0 - scalar
// "(AAB)" thumb joint 1 - scalar
// "(AAC)" thumb joint 2 - scalar
// "(BAA)" index joint 0 - scalar
// "(BAB)" index joint 1 - scalar
// "(BAC)" index joint 2 - scalar
// "(BAD)" index joint 3 - scalar
// "(CAA)" middle joint 0 - scalar
// "(CAB)" middle joint 1 - scalar
// "(CAC)" middle joint 2 - scalar
// "(CAD)" middle joint 3 - scalar
// "(DAA)" ring joint 0 - scalar
// "(DAB)" ring joint 1 - scalar
// "(DAC)" ring joint 2 - scalar
// "(DAD)" ring joint 3 - scalar
// "(EAA)" pinky joint 0 - scalar
// "(EAB)" pinky joint 1 - scalar
// "(EAC)" pinky joint 2 - scalar
// "(EAD)" pinky joint 3 - scalar

// "(AB)"  whole thumb splay - scalar
// "(BB)"  whole index splay - scalar
// "(CB)"  whole middle splay - scalar
// "(DB)"  whole ring splay - scalar
// "(EB)"  whole pinky splay - scalar

// "F" joystick x component - scalar
// "G" joystick y component - scalar
// "H" joystick button - boolean

// "I" trigger button - boolean
// "J" A button - boolean
// "K" B button - boolean

// "L" grab - boolean
// "M" pinch - boolean

// "N" system button (opens SteamVR menu) - boolean

// "O" calibration button - boolean

// "P" trigger value - scalar



void translate(int x, int y,char * thumb){

    char AAA[5];
    char AAB[5];

    itoa(x, AAA, 10);
    itoa(y, AAB, 10);
    
    strcat(thumb,AAA);
    strcat(thumb,"AAB");
    strcat(thumb,AAB);
    strcat(thumb,"\n");

}
 
int app_trans(int x, int y) { 
  
    char thumb[1024] = "AAA"; 
    // Ensure enough space for the new character 
    translate(x,y,thumb);
    if (strlen(thumb) + 1 < sizeof(thumb)) { 
        // Use strcat to add the character 
        printf("%s\n",thumb); 
    } else { 
        printf("Not enough space to add the character.\n"); 
    } 
    vTaskDelay(pdMS_TO_TICKS(1000));
    
return 0;
} 

