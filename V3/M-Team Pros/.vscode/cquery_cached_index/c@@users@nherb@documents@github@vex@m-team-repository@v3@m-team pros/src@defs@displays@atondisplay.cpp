#include "main.h"
#include "display/lvgl.h"
#include "display/lv_conf.h"

bool LablesEnabled = true;

void AtonScreen(void*AtonScreen){
  /*Create label on the screen. By default it will inherit the style of the screen*/
  // lv_obj_t * title = lv_label_create(lv_scr_act(), NULL);
  // lv_label_set_recolor(title, true);
  // lv_label_set_text(title, "#ffffff Autonomous Routines#");
  // lv_obj_align(title, NULL, LV_ALIGN_IN_TOP_MID, 0, 8);  /*Align to the top*/
  //
  // lv_obj_t * about = lv_label_create(lv_scr_act(), NULL);
  // lv_label_set_recolor(about, true);
  // lv_label_set_text(about, "#d9d9d9 Pick a Routine...#");
  // lv_obj_align(about, NULL, LV_ALIGN_IN_TOP_LEFT, 5, 30);  /*Align to the top*/
  //
  // /*Create anew style*/
  // static lv_style_t style_discrpt;
  // lv_style_copy(&style_discrpt, &lv_style_plain);
  // style_discrpt.text.font = &lv_font_dejavu_20;
  // style_discrpt.text.letter_space = 1;
  // style_discrpt.text.line_space = 1;
  // style_discrpt.text.color = LV_COLOR_HEX(0x787878);
  // /*Red style*/
  // static lv_style_t style_red;
  // lv_style_copy(&style_discrpt, &lv_style_plain);
  // style_red.text.font = &lv_font_dejavu_20;
  // style_red.text.letter_space = 1;
  // style_red.text.line_space = 1;
  // style_red.text.color = LV_COLOR_HEX(0xf70808);
  // /*Blue style*/
  // static lv_style_t style_blue;
  // lv_style_copy(&style_discrpt, &lv_style_plain);
  // style_blue.text.font = &lv_font_dejavu_20;
  // style_blue.text.letter_space = 1;
  // style_blue.text.line_space = 1;
  // style_blue.text.color = LV_COLOR_HEX(0x0040ff);
  //
  // lv_obj_t * Aton = lv_label_create(lv_scr_act(), NULL);
  // lv_label_set_recolor(Aton, true);
  // lv_label_set_text(Aton, "#d9d9d9 Pick a Routine...#");
  // lv_obj_align(Aton, NULL, LV_ALIGN_IN_TOP_LEFT, 5, 60);  /*Align to the top*/
  //
  // while(LablesEnabled){
  //   int MainSelectValue = MainAtonSelect.get_value();
  //   int secSelectValue = SecAtonSelect.get_value();
  //   if(MainSelectValue > 3500) {
  //       lv_label_set_text(Aton, "#0DFF00 Testing Aton#");
  //       lv_obj_refresh_style(Aton);
  //   }
  //   else if(MainSelectValue > 2000){
  //       lv_label_set_text(Aton, "#f3f708 Skills#");
  //       lv_obj_refresh_style(Aton);
  //   }
  //
  //   else if(MainSelectValue > 1350) {
  //     lv_obj_set_style(Aton, &style_red);
  //     lv_obj_refresh_style(Aton);
  //       if(secSelectValue > 3600) lv_label_set_text(Aton, "Back Red - Other");
  //       else if(secSelectValue > 1900) lv_label_set_text(Aton, "Back Red - Sniper");
  //       else if(secSelectValue > 450) lv_label_set_text(Aton, "Back Red - Parking");
  //       else if(secSelectValue >= 0) lv_label_set_text(Aton, "Back Red - Normal");
  //       lv_label_refr_text(Aton);
  //   }
  //   else if(MainSelectValue > 775){
  //     lv_obj_set_style(Aton, &style_red);
  //     lv_obj_refresh_style(Aton);
  //       if(secSelectValue > 3600) lv_label_set_text(Aton, "Front Red - Other");
  //       else if(secSelectValue > 1900) lv_label_set_text(Aton, "Front Red - Sniper");
  //       else if(secSelectValue > 450) lv_label_set_text(Aton, "Front Red - Parking");
  //       else if(secSelectValue >= 0) lv_label_set_text(Aton, "Front Red - Normal");
  //
  //   }
  //   else if(MainSelectValue > 225){
  //     lv_obj_set_style(Aton, &style_blue);
  //     lv_obj_refresh_style(Aton);
  //       if(secSelectValue > 3600) lv_label_set_text(Aton, "Back Blue - Other");
  //       else if(secSelectValue > 1900) lv_label_set_text(Aton, "Back Blue - Sniper");
  //       else if(secSelectValue > 450) lv_label_set_text(Aton, "Back Blue - Parking");
  //       else if(secSelectValue >= 0) lv_label_set_text(Aton, "Back Blue - Normal");
  //   }
  //   else if(MainSelectValue >= 0){
  //     lv_obj_set_style(Aton, &style_blue);
  //     lv_obj_refresh_style(Aton);
  //       if(secSelectValue > 3600) lv_label_set_text(Aton, "Front Blue - Other");
  //       else if(secSelectValue > 1900) lv_label_set_text(Aton, "Front Blue - Sniper");
  //       else if(secSelectValue > 450) lv_label_set_text(Aton, "Front Blue - Parking");
  //       else if(secSelectValue >= 0) lv_label_set_text(Aton, "Front Blue - Normal");
  //   }
  //   lv_obj_report_style_mod(NULL);
  //   pros::delay(20);
  // }
}
