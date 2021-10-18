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

