/**
 * @file joy.h
 * @brief コントローラ
 * @author naokichi
 * @date 2023/02/27
 */

#pragma once

#include <windows.h>
#include <xinput.h>

#include <iostream>

#include "speak.h"

/**
 * @brief 自作ライブラリ用の名前空間
 */
namespace my_lib {

/**
 * @brief コントローラ
 */
class Joy {
 private:
  XINPUT_STATE state;

 public:
  SHORT LX, LY, RX, RY;

  Joy();

  /**
   * @brief コントローラの入力状態を更新する
   * @retval TRUE 成功
   * @retval FALSE 失敗
   */
  BOOL UpdateState();
};

}  // namespace my_lib