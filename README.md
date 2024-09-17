# FMDAF team
- Jorge Robles
- Zyanya Orozco
- Diego Ochoa
- Bryan Jimenez

  # Exercise Task

  Grade is 2 over 10. Here are every point less I argued.
  
1. You are missing the CMake file that helps the compiler link the files.  
2. Your comments are in Spanish. This is a warning: Spanish comments are **FORBIDDEN**. If this happens again, the activity will be marked as invalid.  
3. You did not follow the integration testing requirements. I expected to see three tasks, not two (Violation of Requirement 4) [/TaskExercise/Instructions.md]:  
   > "In this test, you will work with 3 LEDs that need to alternate in a sequence with three distinct timings."  
4. The code does not meet Google's coding standards.  
5. I am almost certain that your code does not work.  
6. `void taskFunction() override` is empty; it does nothing.  
7. In `FMDAF/TaskExercise/TaskLed.h`, Line 23: `gpio_set_state(gpio_get_state(pin)^);` - You are not toggling. Why did you lie? Why did you merge this? The correct line should be `gpio_set_state(gpio_get_state(pin)^1);`.
8. You did not wait for my approval on Git. Please create a pull request and do not merge or pre-approve your code without my consent. I will not penalize you further for this.
