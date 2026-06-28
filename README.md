# c-project-2-guess-the-number
project for https://github.com/Harin23/learn-c/tree/main/projects

--- 
instructions:

# Project 2: Guess-the-Number Game

**Module:** 1.2 — Control Flow and Basic I/O  
**Estimated time:** 2–3 hours

## Description

Implement a number-guessing game where the program picks a secret number and the user tries to guess it within a limited number of attempts.

## Requirements

### Functional

1. Pick a random integer between 1 and 100 (inclusive).
2. Allow the user up to 7 guesses.
3. After each guess, print:
   - "Too high" if guess > secret
   - "Too low" if guess < secret
   - "Correct!" if guess == secret (end game, win)
4. If all 7 guesses are used without winning, reveal the secret number.
5. Ask whether to play again (`y`/`n`).

### Random Number Generation

Use one of these approaches (document your choice in a code comment):

- **Preferred:** Read bytes from `/dev/urandom` and scale to 1–100
- **Acceptable:** `srand(time(NULL))` + `rand() % 100 + 1` (discuss predictability)

## Technical Requirements

- Single file: `guess.c`
- Validate that guesses are integers in range 1–100
- Handle invalid input without crashing

## Rubric

| Criterion | Points |
|-----------|--------|
| Random number in correct range | 20 |
| High/low feedback correct | 25 |
| Win/lose conditions correct | 25 |
| Input validation | 20 |
| Play-again loop works | 10 |
| **Total** | **100** |

## Test Cases

1. Win on first guess (lucky)
2. Use all 7 guesses incorrectly — secret revealed
3. Enter `50.5` or `abc` — re-prompt without crash
4. Play again `n` — program exits cleanly

## Extension (Optional)

Track and print the user's win/loss record across multiple rounds.
