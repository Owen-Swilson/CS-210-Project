# CS-210-Project
Simple C++ grocery tracker that reads from a file and lets users search, count, and visualize item frequencies. Project final for C++ course.

## Project Summary
This project takes a grocery item list from a file and tracks how often each item shows up. The idea is pretty simple, but useful. It’s basically a lightweight way to see buying patterns without overcomplicating it.

The program reads from an input file, stores the data, and then lets the user interact with it through a menu. You can search for specific items, print all item frequencies, or generate a histogram. It’s not flashy, but it works and solves the problem it was built for.

---

## What I Did Well
I think the strongest part of this project is that everything actually works together the way it’s supposed to. The file input, the data tracking, and the menu system all connect cleanly.

I also did a good job breaking things into functions instead of dumping everything into main(). That made debugging way easier and kept things from turning into a mess.

---

## Areas for Improvement
If I were to go back and improve this, I would tighten up input validation even more and make the program more resilient overall. Right now it works, but it could be more defensive.

I’d also look at efficiency if the dataset got bigger. For this project it’s fine, but scaling it up would probably require better data handling or different structures.

---

## Challenges and How I Overcame Them
The biggest issue I ran into was with user input in the menu. At one point, if you entered something invalid, the program would get stuck in an infinite loop just spamming error messages. It wouldn’t recover, it would just keep going.

I had to go back and fix that by adjusting the input validation and adding a proper break/clear so the program could recover instead of locking itself up. That was one of those moments where everything “looked” right but clearly wasn’t.

File input was another area that took some trial and error. When it didn’t work, it wasn’t obvious why, so I had to slow down and test step by step.

For both of these, I leaned on zyBooks examples, tested small pieces at a time, and just kept working through it until it behaved correctly.

---

## Transferable Skills
This project helped me reinforce a few core skills that carry over to pretty much everything:
- Working with file input and output
- Structuring programs using functions
- Debugging issues that aren’t immediately obvious
- Building something that a user can actually interact with

That last one is big. It’s one thing to write code, it’s another to make it usable.

---

## Code Maintainability and Readability
I kept things maintainable by splitting the program into smaller functions that each handle one job. That makes it easier to track down issues and update things later without breaking everything else.

I also used straightforward naming and added comments where they actually help, not just for the sake of it. The goal was to make it readable without overexplaining every single line.
