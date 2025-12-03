This is the updated version of the game.
I added extra features and fixed some small issues to make the game smoother.
All the modifications are clearly listed below.

1. Visual & Layout Fixes

2. New Game Mechanics Added

• Score System
>Score increases by 1 point every time you dodge an obstacle.
>Score displays on the screen continuously.

• Lives System
>Added 3 lives.
>Collision reduces 1 life instead of ending the game instantly.

• High Score Saving
>Added a highscore.txt file.
>Game reads previous high score at start and updates it if the new one is higher.

• Speed Increase Feature
>After every 5 points, the game becomes slightly faster.
>Makes gameplay more challenging as score increases.

3. Controls Added

Action	Key
>Move Left	← arrow key
>Move Right	→ arrow key
>Pause Game	P
>Quit Game	Q
>Restart After   R
Game is Over       

All controls were missing in the original code.

4. Gameplay Improvements

• Pause Feature
>Press P anytime to pause the game.
>Press any key to resume.

• Quit Feature
>Press Q to exit instantly.

• Restart Option
>After Game Over, player can press R to restart.

5. Added Color Formatting

>Obstacle is shown in red.
>Player is shown in green.
>Border is highlighted in cyan.
>This makes lanes and objects clearer during gameplay.

6. Clean Code Structure
>Created a separate drawBorder() function.
>Removed unnecessary spaces.
>Made the whole output look cleaner and more readable.