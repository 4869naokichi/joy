/**
 * @file joy.cpp
 * @brief コントローラ
 * @author naokichi
 * @date 2023/02/27
 */

#include <joy.h>

namespace my_lib {

Joy::Joy() : LX(0), LY(0), RX(0), RY(0) { ; }

BOOL Joy::UpdateState() {
  DWORD dwResult = XInputGetState(0, &state);
  if (dwResult != ERROR_SUCCESS) {
    std::cout << "コントローラの入力を取得できません。" << std::endl;
    Speak("コントローラの入力を取得できません。");
    return FALSE;
  }
  LX = state.Gamepad.sThumbLX;
  LY = state.Gamepad.sThumbLY;
  RX = state.Gamepad.sThumbRX;
  RY = state.Gamepad.sThumbRY;
  return TRUE;
}

}  // namespace my_lib