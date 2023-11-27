# push_swap
(42 Malaga) "Push Swap" is a straightforward algorithmic project at 42. The objective is to generate a set of instructions to be printed to the standard output, guiding the sorting of numbers received in stack A from the smallest to the largest. The main goal is to accomplish this task using the minimal number of actions possible.

##Actions
|      | Instruction         | Action                                                |
|------|---------------------|-------------------------------------------------------|
| sa   | swap a              | swaps the 2 elements of the top of stack a            |
| sb   | swap b              | swaps the 2 elements of the top of stack b             |
| ss   | swap a + swap b     | both sa and sb                                        |
| pa   | push a              | moves the element of the top of stack b at the top of stack a |
| pb   | push b              | moves the element of the top of stack a at the top of stack b |
| ra   | rotate a            | shifts all elements of stack a from bottom to top     |
| rb   | rotate b            | shifts all elements of stack b from bottom to top     |
| rr   | rotate a + rotate b | both ra and rb                                        |
| rra  | reverse rotate a    | shifts all elements of stack a from top to bottom     |
| rrb  | reverse rotate b    | shifts all elements of stack b from top to bottom     |
| rrr  | rra + rrb             | both rra and rrb                                    |

##Examples
```bash
./push_swap 3 4 432 43 3234 633 23 856 9
pb
pb
ra
ra
ra
ra
pb
ra
pb
pb
pb
ra
pa
ra
pa
rra
pa
ra
pa
rra
pa
pa
```
