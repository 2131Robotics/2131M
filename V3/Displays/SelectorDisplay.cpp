#include "N_Custom/declars/Displays/SelectorDisplay.hpp"
void LGVLtest(){
  LV_IMG_DECLARE(ResetFieldCut);

  lv_obj_t * img1 = lv_img_create(lv_scr_act(), NULL);
  lv_img_set_src(img1, &ResetFieldCut);
  lv_obj_align(img1, NULL, LV_ALIGN_IN_TOP_LEFT, 20, 40);
}
