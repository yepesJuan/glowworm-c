# glowworm-c
an assigment from ucf cs1 called glowworm

Abstract
In this assignment, you will write a main() function that can process command line arguments – parameters that are typed at the command line and passed into your program right when it starts running (as opposed to using scanf() to get input from a user after your program has already started running). Those parameters will be passed to your main() function as an array of strings, and so this program will also jog your memory with respect to using strings in C.
On the software engineering side of things, you will learn to construct programs that use multiple source files and custom header (.h) files. This assignment will also help you hone your ability to acquire new knowledge by reading technical specifications. If you end up pursuing a career as a software developer, the ability to rapidly digest technical documentation and work with new software libraries will be absolutely critical to your work, and this assignment will provide you with an exercise in doing just that.
Finally, this assignment is intended to rekindle your knowledge of C programming and stoke your creative problem solving skills.
Deliverables
Glowworm.c
Note! The capitalization and spelling of your filename matter! Note! Code must be tested on Eustis, but submitted via Webcourses.
1. Important Note: Test Case Files Look Wonky in Notepad
Included with this assignment are several test cases, along with output files showing exactly what your output should look like when you run those test cases. You will have to refer to those as the gold standard for how your output should be formatted.
Please note that if you open those files in Notepad, they will appear to contain one long line of text. That’s because Notepad handles end-of-line characters differently from Linux and Unix-based systems. One solution is to view those files in a text editor designed for coding, such as Atom, Sublime, or Notepad++. For those using Mac or Linux systems, the input files should look just fine.
2. Overview
In this program, you will print an adorable little glowworm as it eats its way through an input string passed to your program. Your program will receive two input parameters to start with: an integer indicating the maximum length of your glowworm, and a string of characters for the glowworm to eat. Those input parameters will be passed to you as command line arguments. The process for that is described below in Appendix B (“Processing Command Line Arguments”) (pg. 17).
The glowworm always starts with three characters: a tail (‘~’), a head (‘G’), and a big segment between the tail and the head (‘O’). Overall, a new glowworm always starts out looking like this: “~OG”
Your program should always start by printing the following:
1. The input string passed to your program for the glowworm to eat, followed by two newline characters (‘\n’), followed by “Glowworm appears! Hooray!” and another newline character.
2. The initial glowworm (“~OG”), followed by a single newline character (‘\n’).
3. A ledge of equal signs (‘=’), followed by two newline characters (‘\n’). The number of equal signs printed should always match the number passed to your program to indicate the maximum length of your glowworm.
For example, if someone runs your program with a maximum glowworm length of 7 and “oOo@x” as the input string to be consumed by the glowworm, you should start out by printing the following:
     oOo@x
Glowworm appears! Hooray!
~OG
=======
 Next, process each character in the input string. The table below shows how your glowworm should react to each possible character in an input string. Following the table is a description of the output that your program should produce for each of these glowworm actions/behaviors.

   Character Description
    'o' (lowercase letter o)
'O' (uppercase letter o)
'@' (at symbol)
  Any of these characters will cause your glowworm to grow a new segment.
 's' (lowercase letter s)
'S' (uppercase letter s)
'-' (minus sign)
'=' (equal symbol)
Any of these characters will cause your glowworm to shrink by one segment. Any of these characters will cause your glowworm to inch forward.
     'x' (lowercase letter x)
'X' (uppercase letter x)
'%' (percent sign)
   Any one of these characters will cause your glowworm to die. SAD.
 Any character not listed in the table above should cause your glowworm to chill.
Side Note:
There are certain characters that cause Linux to do wonky things with command line arguments. Accordingly, we guarantee that the following characters will never appear in the command line arguments passed to your program: dollar sign (‘$’), opening parenthesis (‘(‘), closing parenthesis (‘)’), exclamation point (‘!’), hash (‘#’), ampersand (‘&’), backslash (‘\’), pipe (‘|’), semi-colon (‘;’), tilde (‘~’), asterisk (‘*’), period (‘.’), space (‘ ’), single quotes (‘ and ’), double quotes (“ and ”), and redirection symbols (‘<’ and ‘>’). I think any other standard keyboard characters should be fair game, but if you have any questions about odd behaviors that you’re getting with non-alphabetic and non-numeric input characters, feel free to ask – although the answer is almost certainly, “Don’t worry about that.”
Here’s how each of the glowworm behaviors listed above should work:
2.1 Growing
If your glowworm eats a character that causes it to grow, it should gain a single ‘o’ segment between its tail and its capital ‘O’ segment, causing all other segments to move forward. For example, the following output starts with an existing glowworm and shows exactly what the output should be when it grows by one segment:
    ~OG =======
Glowworm grows:
~oOG
=======
 Note: In this diagram, I have omitted all the output leading up to the “~OG” line. I similarly omit all the output leading up to the first line in all the other glowworm diagrams in the examples below. Note also that the output always has a blank line beneath the equal symbols.

A similar thing happens even if the glowworm has inched forward to another position on the platform:
   ~OG =======
Glowworm grows:
  ~oOG
=======
 If the glowworm is already maximally long, then consuming a growth character should cause it to chill instead:
   ~ooooOG
=======
Glowworm chills:
~ooooOG
=======
 2.2 Shrinking
If your glowworm eats a character that causes it to shrink, it should lose an ‘o’ segment, causing all segments after that one to pull backward. For example, the following output starts with an existing glowworm and shows exactly what the output should be when it shrinks by one segment:
   ~ooOG
=======
Glowworm shrinks:
~oOG
=======
 If the glowworm has no lowercase ‘o’ segments, then it should chill instead:
   ~OG =======
Glowworm chills:
   ~OG
=======
 
2.3 Inching Forward
If your glowworm eats a character that causes it to inch forward, all segments should move forward in tandem. For example, the following output starts with an existing glowworm and shows exactly what the output should be when it inches forward:
   ~ooOG
=======
Glowworm inches forward:
 ~ooOG
=======
 2.4 Dying
If your glowworm eats a character that causes it to die, the “OG” in the glowworm string should be replaced with “Xx” (an uppercase ‘X’ followed by a lowercase ‘x’), and the program should then terminate without processing any remaining letters in the string that the glowworm was consuming:
     ~ooOG
=======
Glowworm meets its demise. SAD.
  ~ooXx
=======
 2.5 Chillin’
If the glowworm consumes a character not associated with one of the behaviors/actions above, the glowworm should not move or change in any way, and you should indicate that the glowworm is chillin’, like so:
    ~ooOG
=======
Glowworm chills:
 ~ooOG
=======
 
2.6 Magical, Translocational Glowworm Shenanigans
PLOT TWIST! This is some sort of magical, translocational glowworm we’re dealing with. If it reaches the end of the platform it’s on and then grows or inches forward, it wraps back around to the beginning of the platform. The following output examples illustrate how to handle wrap-around situations with the glowworm.
If the glowworm has grown and/or inched forward to the end of the platform and then consumes a character that causes it to grow, its head should wrap back around to the beginning of the platform:
     ~ooOG
=======
Glowworm grows:
G ~oooO
=======
 From there, if the glowworm grows again, the behavior is as follows:
   G ~oooO
=======
Glowworm grows:
OG~oooo
=======
 Here’s how shrinking affects a glowworm that has already wrapped around to the start of the platform:
   OG  ~oo
=======
Glowworm shrinks:
G   ~oO
=======
 Here’s another example. Notice that the tail always remains stationary when the glowworm shrinks:
   G ~oO =======
Glowworm shrinks:
    ~OG
=======
 
Here’s an example in which a wrapped-around glowworm inches forward:
OG ~ooo
=======
Glowworm inches forward:
oOG ~oo
=======
A wrapped-around glowworm can inch forward even if it is taking up the entire platform:
oOG~ooo
=======
Glowworm inches forward:
ooOG~oo
=======
