#include "main.h"
#include "display/lvgl.h"
#include "display/lv_conf.h"

/**
 * Creates a GUI to allow the user to see which program will run using 
 * lvgt interface.
 * - Each Value will switch the text displayed inside the lable
**/

bool LablesEnabled = true;

void AtonScreen(void*AtonScreen){
  // /*Create label on the screen. By default it will inherit the style of the screen*/
  static lv_obj_t * title = lv_label_create(lv_scr_act(), NULL);
  lv_label_set_recolor(title, true);
  lv_label_set_text(title, "#ffffff Autonomous Routines#");
  lv_obj_align(title, NULL, LV_ALIGN_IN_TOP_MID, 0, 8);  /*Align to the top*/

  static lv_obj_t * des = lv_label_create(lv_scr_act(), NULL);
  lv_label_set_recolor(des, true);
  lv_label_set_text(des, "#00ad0e What shall you chooose to execute?#");
  lv_obj_align(des, NULL, LV_ALIGN_IN_TOP_LEFT, 5, 30);  /*Align to the top*/

  static lv_obj_t * Aton = lv_label_create(lv_scr_act(), NULL);
  lv_label_set_recolor(Aton, true);
  // lv_label_set_text(Aton, "#0DFF00 Pick a Routine...#");
  lv_obj_set_pos(Aton,5, 60);  /*Align to the top*/
  
  static lv_obj_t * about = lv_label_create(lv_scr_act(), NULL);
  lv_label_set_recolor(about, true);
  // lv_label_set_long_mode(about, LV_LABEL_LONG_BREAK);
  lv_label_set_text(about, "#d9d9d9 Pick a Routine...atons#");
  lv_obj_align(about, NULL, LV_ALIGN_IN_TOP_LEFT, 30, 90);  /*Align to the top*/
  
  /*Create anew style*/
  static lv_style_t style_discrpt;
  lv_style_copy(&style_discrpt, &lv_style_plain);
  style_discrpt.text.font = &lv_font_dejavu_20;
  style_discrpt.text.letter_space = 1;
  style_discrpt.text.line_space = 1;
  style_discrpt.text.color = LV_COLOR_HEX(0x787878);
  /*Red style*/
  static lv_style_t style_red;
  lv_style_copy(&style_discrpt, &lv_style_plain);
  style_red.text.font = &lv_font_dejavu_20;
  style_red.text.letter_space = 1;
  style_red.text.line_space = 1;
  style_red.text.color = LV_COLOR_HEX(0xf70808);
  /*Blue style*/
  static lv_style_t style_blue;
  lv_style_copy(&style_discrpt, &lv_style_plain);
  style_blue.text.font = &lv_font_dejavu_20;
  style_blue.text.letter_space = 1;
  style_blue.text.line_space = 1;
  style_blue.text.color = LV_COLOR_HEX(0x0040ff);
  
////////////////////////////////////////////////////////////////////////

  while(LablesEnabled){
    int MainSelectValue = MainAtonSelect.get_value();
    int secSelectValue = SecAtonSelect.get_value();
    static int MainSelectValueWas;
    static int secSelectValueWas;
    if(std::abs(MainSelectValueWas-MainSelectValue)>50 || std::abs(secSelectValueWas-secSelectValue)>50){
      if(MainSelectValue > 3500) {
          lv_label_set_text(Aton, "#940099 Testing Aton#");
          lv_label_set_text(about, "#940099 What broke now??#");
          // lv_obj_refresh_style(Aton);
      }
      else if(MainSelectValue > 2000){
          lv_label_set_text(Aton, "#f3f708 Skills#");
          lv_label_set_text(about, "#f3f708 Lets get this 27!");
          // lv_obj_refresh_style(Aton);
      }

      //BACK RED DISCRIPTIONS
      else if(MainSelectValue > 1350) {
        // lv_obj_set_style(Aton, &style_red);
        // lv_obj_refresh_style(Aton);
        if(secSelectValue > 3600){
          lv_label_set_text(Aton, "#ff0000 Back Red - Other#");
          lv_label_set_text(about, "#ff0000 Points: 7\n#ff0000 Grabs 1st ball from cap and scores it. Flips seconed\n#ff0000 cap and returns back to starting tile and snipes our\n#ff0000 own top flag then parks.");
        }
        else if(secSelectValue > 1900){
          lv_label_set_text(Aton, "#ff0000 Back Red - Sniper #");
          lv_label_set_text(about, "#ff0000 Points: 8 - Swing: 2:2\n#ff0000 Grabs 2nd ball from platform then shoots top\n#ff0000 middle flag. Then grabs 1 more ball and toggles\n#ff0000 alliances top flag back to our color.#");
        }
        else if(secSelectValue > 450){
          lv_label_set_text(Aton, "#ff0000 Back Red - Parking#");
          lv_label_set_text(about, "#ff0000 Points: 8 - Swing: 2:2\n#ff0000 Gets 2nd ball from scoring first cap, grabs\n#ff0000 the seconed cap with the lift turnes and shoots\n#ff0000 opponets middle flag. Then stacks\n#ff0000 the cap in the lift and parks.");
        }
        else if(secSelectValue >= 0){
          lv_label_set_text(Aton, "#ff0000 Back Red - Normal#");
          lv_label_set_text(about, "#ff0000 Points: 6\n#ff0000 Gets 1st cap and ball, stacks seconed cap\n#ff0000 then parks.#");
        }
        // lv_label_refr_text(Aton);
      }

      //FRONT RED DISCRIPTIONS
      else if(MainSelectValue > 775){
        // lv_obj_set_style(Aton, &style_red);
        // lv_obj_refresh_style(Aton);
        if(secSelectValue > 3600){
          lv_label_set_text(Aton, "#ff0000 Front Red - Other#");
          lv_label_set_text(about, "#ff0000 Points: 6\n#ff0000 None! Got any ideas??");
        } 
        else if(secSelectValue > 1900){
          lv_label_set_text(Aton, "#ff0000 Front Red - Sniper#");
          lv_label_set_text(about, "#ff0000 Points: 8 - Swing: 2:2\n#ff0000 Grabs 2nd ball off the platform turns and shoots\n#ff0000 our row of flags. Grabs 1st ball from closest cap\n#ff0000 and 2nd from propped up cap and hits opponents\n#ff0000 top flag.#");
        }
        else if(secSelectValue > 450){
          lv_label_set_text(Aton, "#ff0000 Front Red - Parking#");
          lv_label_set_text(about, "#ff0000 Points: Points: 8 - Swing: 2:2\n#ff0000 Grabs proped up ball and scores cap backs up and\n#ff0000 swings with a drift away shot on middl pole. Then\n#ff0000 grabs another ball while flipping 2nd cap and the\n#ff0000 2nd ball from the platform then parks and shoots\n#ff0000 opponents flags.#");
        } 
        else if(secSelectValue >= 0){
          lv_label_set_text(Aton, "#ff0000 Front Red - Normal#");
          lv_label_set_text(about, "#ff0000 Points: 10\n#ff0000 Grabs 2nd ball and returns to fire both high\n#ff0000 flags. Then grabs ball while toggling bottom flag.\n#ff0000 Then turns, grabs 2nd b all flips the cap and shoots\n#ff0000 two middle high flags at the very end seconeds.");
        }
      }
      //BACK BLUE DISCRIPTIONS
      else if(MainSelectValue > 225){
        // lv_obj_set_style(Aton, &style_blue);
        // lv_obj_refresh_style(Aton);
        if(secSelectValue > 3600){
          lv_label_set_text(Aton, "#0000ff Back Blue - Other#");
          lv_label_set_text(about, "#0000ff Points: 7\n#0000ff Grabs 1st ball from cap and scores it. Flips seconed\n#0000ff cap and returns back to starting tile and snipes our\n#0000ff own top flag then parks.");
        }
        else if(secSelectValue > 1900){
          lv_label_set_text(Aton, "#0000ff Back Blue - Sniper #");
          lv_label_set_text(about, "#0000ff Points: 8 - Swing: 2:2\n#0000ff Grabs 2nd ball from platform then shoots top\n#0000ff middle flag. Then grabs 1 more ball and toggles\n#0000ff alliances top flag back to our color.#");
        }
        else if(secSelectValue > 450){
          lv_label_set_text(Aton, "#0000ff Back Blue - Parking#");
          lv_label_set_text(about, "#0000ff Points: 8 - Swing: 2:2\n#0000ff Gets 2nd ball from scoring first cap, grabs\n#0000ff the seconed cap with the lift turnes and shoots\n#0000ff opponets middle flag. Then stacks\n#0000ff the cap in the lift and parks.");
        }
        else if(secSelectValue >= 0){
          lv_label_set_text(Aton, "#0000ff Back Blue - Normal#");
          lv_label_set_text(about, "#0000ff Points: 6\n#0000ff Gets 1st cap and ball, stacks seconed cap\n#0000ff then parks.#");
        }
      }
      //FRONT BLUE DISCRIPTIONS
      else if(MainSelectValue >= 0){
        // lv_obj_set_style(Aton, &style_blue);
        // lv_obj_refresh_style(Aton);
        if(secSelectValue > 3600){
          lv_label_set_text(Aton, "#0000ff Front Blue - Other#");
          lv_label_set_text(about, "#0000ff Points: 6\n#0000ff None! Got any ideas??");
        } 
        else if(secSelectValue > 1900){
          lv_label_set_text(Aton, "#0000ff Front Blue - Sniper#");
          lv_label_set_text(about, "#0000ff Points: 8 - Swing: 2:2\n#0000ff Grabs 2nd ball off the platform turns and shoots\n#0000ff our row of flags. Grabs 1st ball from closest cap\n#0000ff and 2nd from propped up cap and hits opponents\n#0000ff top flag.#");
        }
        else if(secSelectValue > 450){
          lv_label_set_text(Aton, "#0000ff Front Blue - Parking#");
          lv_label_set_text(about, "#0000ff Points: Points: 8 - Swing: 2:2\n#0000ff Grabs proped up ball and scores cap backs up and\n#0000ff swings with a drift away shot on middl pole. Then\n#0000ff grabs another ball while flipping 2nd cap and the\n#0000ff 2nd ball from the platform then parks and shoots\n#0000ff opponents flags.#");
        } 
        else if(secSelectValue >= 0){
          lv_label_set_text(Aton, "#0000ff Front Blue - Normal#");
          lv_label_set_text(about, "#0000ff Points: 10\n#0000ff Grabs 2nd ball and returns to fire both high\n#0000ff flags. Then grabs ball while toggling bottom flag.\n#0000ff Then turns, grabs 2nd b all flips the cap and shoots\n#0000ff two middle high flags at the very end seconeds.");
        }
      }
    }
    MainSelectValueWas=MainSelectValue;
    secSelectValueWas=secSelectValue;
    pros::delay(20);
  }
}
