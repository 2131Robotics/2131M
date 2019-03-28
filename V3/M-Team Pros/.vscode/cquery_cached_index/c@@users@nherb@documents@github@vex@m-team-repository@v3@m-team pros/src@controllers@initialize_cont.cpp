#include "main.h"
#include "N_Custom/declars/Systems/Drive.hpp"
#include "display/lvgl.h"
/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
//  static lv_res_t btn_click_action(lv_obj_t * btn)
// {
//     // uint8_t id = lv_obj_get_free_num(btn);
//     //
//     // printf("Button %d is pressed\n", id);
//     // printf("Button %d is released\n", id);
//     //
//     // /* The button is released.
//     //  * Make something here */
//     //
//     // return LV_RES_OK; /*Return OK if the button is not deleted*/
// }
void LGVLtest(){
//   /*Called when a button is released ot long pressed*/
// static lv_res_t btnm_action(lv_obj_t * btnm, const char *txt)
// {
//     printf("Button: %s released\n", txt);
//
//     return LV_RES_OK; /*Return OK because the button matrix is not deleted*/
// }
//   /*Create a button descriptor string array*/
//   static const char * btnm_map[] = {"1", "2", "3", "4", "5", "\n",
//                              "6", "7", "8", "9", "0", "\n",
//                              "\202Action1", "Action2", ""};
//
//
//
//
//   /*Create a default button matrix*/
//   lv_obj_t * btnm1 = lv_btnm_create(lv_scr_act(), NULL);
//   lv_btnm_set_map(btnm1, btnm_map);
//   lv_btnm_set_action(btnm1, btnm_q3action);
//   lv_obj_set_size(btnm1, LV_HOR_RES, LV_VER_RES / 2);
//
//   /*Create a new style for the button matrix back ground*/
//   static lv_style_t style_bg;
//   lv_style_copy(&style_bg, &lv_style_plain);
//   style_bg.body.main_color = LV_COLOR_SILVER;
//   style_bg.body.grad_color = LV_COLOR_SILVER;
//   style_bg.body.padding.hor = 0;
//   style_bg.body.padding.ver = 0;
//   style_bg.body.padding.inner = 0;
//
//   /*Create 2 button styles*/
//   static lv_style_t style_btn_rel;
//   static lv_style_t style_btn_pr;
//   lv_style_copy(&style_btn_rel, &lv_style_btn_rel);
//   style_btn_rel.body.main_color = LV_COLOR_MAKE(0x30, 0x30, 0x30);
//   style_btn_rel.body.grad_color = LV_COLOR_BLACK;
//   style_btn_rel.body.border.color = LV_COLOR_SILVER;
//   style_btn_rel.body.border.width = 1;
//   style_btn_rel.body.border.opa = LV_OPA_50;
//   style_btn_rel.body.radius = 0;
//
//   lv_style_copy(&style_btn_pr, &style_btn_rel);
//   style_btn_pr.body.main_color = LV_COLOR_MAKE(0x55, 0x96, 0xd8);
//   style_btn_pr.body.grad_color = LV_COLOR_MAKE(0x37, 0x62, 0x90);
//   style_btn_pr.text.color = LV_COLOR_MAKE(0xbb, 0xd5, 0xf1);
//
//   /*Create a second button matrix with the new styles*/
//   lv_obj_t * btnm2 = lv_btnm_create(lv_scr_act(), btnm1);
//   lv_btnm_set_style(btnm2, LV_BTNM_STYLE_BG, &style_bg);
//   lv_btnm_set_style(btnm2, LV_BTNM_STYLE_BTN_REL, &style_btn_rel);
//   lv_btnm_set_style(btnm2, LV_BTNM_STYLE_BTN_PR, &style_btn_pr);
//   lv_obj_align(btnm2, btnm1, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
}
void initialize() {
  Drive::LeftFMotor.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
  Drive::LeftBMotor.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
  Drive::RightFMotor.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
  Drive::RightBMotor.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);

  Catapult::CatapultMotor.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);

  Intake::IntakeMotor.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);

  Lift::LiftMotor.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);

  Flipper::FlipMotor.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);

  Drive::LeftFMotor.tarePosition();
  Drive::LeftBMotor.tarePosition();
  Drive::RightFMotor.tarePosition();
  Drive::RightBMotor.tarePosition();

  Flipper::FlipMotor.tarePosition();
  Lift::LiftMotor.tarePosition();

  //LGVLtest();

  // pros::Task CatapultTask (usefull, (void) "PROS", TASK_PRIORITY_DEFAULT,
  // TASK_STACK_DEPTH_DEFAULT, "My Task");
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
  //future aton selector
}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}
