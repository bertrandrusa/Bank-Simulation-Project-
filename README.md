

## Background

The specifications for the simulation are captured in exercises 6 and 7 found at the end of Chapter 13. For your convenience, they are repeated here.

### Programming Problem 6

Implement the event-driven simulation of a bank that chapter 13 described. A queue of arrival events will represent the line of customers in the bank. Maintain the arrival events and departure events in a priority queue, sorted by the time of the event. Use a link-based implementation for the priority queue.

The input is a text file of arrival and transaction times. Each line of the file contains the arrival time and required transaction time for a customer. The arrival times are ordered by increasing time.

Your program must count customers and keep track of their cumulative waiting time. These statistics are sufficient to compute the average waiting time after the last event has been processed. Display a trace of the events executed and a summary of the computed statistics (the total number of arrivals and average time spent waiting in line). 

For example, given the input file shown below (the column headers are just informative; the [actual input file](src/main/resources/main_data.txt) will not contain column headers)

| Arrival Time | Transaction Duration |
|--------------|----------------------|
| 1            | 5                    |
| 2            | 5                    |
| 4            | 5                    |
| 20           | 5                    |
| 22           | 5                    |
| 24           | 5                    |
| 26           | 5                    |
| 28           | 5                    |
| 30           | 5                    |
| 88           | 3                    |

your simulation should produce the following output:

```text
Simulation Begins
Processing an arrival event at time:    1
Processing an arrival event at time:    2
Processing an arrival event at time:    4
Processing a departure event at time:   6
Processing a departure event at time:   11
Processing a departure event at time:   16
Processing an arrival event at time:    20
Processing an arrival event at time:    22
Processing an arrival event at time:    24
Processing a departure event at time:   25
Processing an arrival event at time:    26
Processing an arrival event at time:    28
Processing an arrival event at time:    30
Processing a departure event at time:   30
Processing a departure event at time:   35
Processing a departure event at time:   40
Processing a departure event at time:   45
Processing a departure event at time:   50
Processing an arrival event at time:    88
Processing a departure event at time:   91
Simulation Ends
Final Statistics:
Total number of people processed:       10
Average amount of time spent waiting:   5.6
```

Completing this (exercise 6) successfully will guarantee _at least_ a C for your exam grade.

Programming Problem 7 outlines the steps necessary to guarantee higher grades.

### Programming Problem 7

Modify and expand the event-driven simulation program that you wrote in Programming Problem 6.

1. Add an operation that displays the event queue. Completing this step successfully will guarantee _at least_ a C+ for your exam grade.
2. Add some statistics to the simulation. For example, compute the maximum wait in line, the average length of the line, and the maximum length of the line. Completing this step successfully will guarantee _at least_ a B for your exam grade.
3. Modify the simulation so that it accounts for three tellers, each with a distinct line. You should keep in mind that there should be
   * Three queues, one for each teller
   * A rule that chooses a line when processing an arrival event (for example, enter the shortest line)
   * Three distinct departure events, one for each line
   * Rules for breaking ties in the event queue

   Run both this simulation and the original simulation on several sets of input data. How do the statistics compare?  Completing this step successfully will guarantee _at least_ an A- for your exam grade.
4. The bank is considering the following change: Instead of having three distinct lines (one for each teller), there will be a single line for the three tellers. The person at the front of the line will go to the first available teller. Modify the simulation of part c to account for this variation. Run both simulations on several sets of input data. How do the various statistics compare (averages and maximums)? What can you conclude about having a single line as opposed to having distinct lines? Completing this step successfully will guarantee _at least_ an A for your exam grade.

**Note**: These guaranteed minimum grades presume that your team presents their results during the final exam period to the class.

## Getting Started

After accepting this assignment with the provided [GitHub Classroom Assignment link](https://classroom.github.com/a/baFqDKja), decide how you want to work with your newly created repository:

- Using Codespaces directly in your web browser that employees the Visual Studio Code online IDE, or
- Using the IDE of your choice on your local machine

### Codespaces

If a Codespace is available for use (and this is your preferred method of development), open your new created repository in a Codespace.

At this point, you can skip to [Creating a development branch](#creating-a-development-branch).

### Local Development

Depending upon the IDE of your choice, many of the following steps may be taken within your IDE. It is up to you to discover these tools (assuming they're available) and learn how to use them appropriately as desired. The following instructions are assumed to take place within a terminal window. Note: many IDEs provide a terminal window as well.

#### Cloning your repository

The command you use to clone is slightly different depending upon whether you're using https or ssh.

If you're using the https protocol, your clone command is:

```shell
git clone https://github.com/msu-csc232/<repo-name>.git
```

If you're using the `ssh` protocol, your clone command is:

```shell
git clone git@github.com:msu-csc232/<repo-name>.git
```

After cloning the repository, navigate into the newly cloned repository:

```shell
cd <repo-name>
```

#### Creating a development branch

Next, create a branch named `develop`. Please note: The name of this branch **must** be as specified and will be, to the grading scripts, case-sensitive.

```shell
git checkout -b develop
```

Make sure you are on the `develop` branch before you get started. Make all your commits on the `develop` branch.

```bash
git status
```

_You may have to type the `q` character to get back to the command line prompt after viewing the status._

## Tasks

As stated, this is a _group_ assignment. As such, this requires a _group_ effort. In addition to program correctness, the group's grade will also be based on the extent to which the group works as such.

Group collaboration will be assessed on two fronts:

1. **Contribution to source code**: `git blame` will be used to see who did what in this project. It is expected that each member of the group contribute roughly equal amounts to the final solution.
2. **Contribution to final presentation**: Each group will present their design and implementation to the class during our scheduled exam period. Each member of the group is expected to participate in some way, shape or form, in the final presentation to the class.

Remember: The grader will execute the `google-tests` target when grading assignment (possibly with different input data placed in the [test_data.txt](src/test/resources/test_data.txt)) so you must make sure the simulation runs in this target by reading that particular data file.

### Strategies for Group Collaboration

The book walks through a great deal of the design process for this simulation. In particular, a number of functions are outlined in pseudocode:

```text
simulate() : void
processArrival(arrivalEvent: Event, eventPriorityQueue: PriorityQueue, bankLine: Queue) : void
processDeparture(departureEvent: Event, eventPriorityQueue: PriorityQueue, bankLine: Queue) : void
```

NOTES:

* all functions, including those listed above, should be encapsulated in the `csc232` namespace.
* these are merely suggestions; part of your grade is related to your own program design. The only real _hard_ requirement is that your simulation is run from a function with the following signature:

```c++
void csc232::simulate(const std::string &fileName);
```

where `fileName` is the name of the simulation input data (e.g., in the Google test runner, this is `text_data.txt`, the same file found in the [src/test/resources](src/test/resources) folder of this repository). Note, for the test target to actually test your simulation, you must toggle the `SIMULATE_FUNCTION_IMPLEMENTED` definition from `FALSE` to `TRUE`.

The easiest way to split up this work without having to modify the `CMakeLists.txt` file would be to create separate header files that are included in the `csc232.h` file. For example, one strategy could do the following:

1. One member creates a new file named `loader.h` in the `include` folder that defines a function which loads the data from a given file into the appropriate structure for subsequent processing. Once this file is created, add a `#include "loader.h"` line to the `csc232.h` file.
2. Another member creates a new file named `processor.h` in the `include` folder that defines one or more functions for processing arrival and departure events. Once this file is created, add a similar `#include` line to the `csc232.h` file
3. The third member implements the `simulate` function already included for you in `csc232.h`

Again, the above strategy is just a suggestion; one that doesn't require any changes to the definitions of the existing targets prescribed by the `CMakeLists.txt` file and guarantees a nice division of labor.

## Submission Details

Before submitting your assignment, be sure you have pushed all your changes to GitHub. If this is the first time you're pushing your changes, the push command will look like:

```bash
git push -u origin develop
```

If you've already set up remote tracking (using the `-u origin develop` switch), then all you need to do is type

```bash
git push
```

As usual, prior to submitting your assignment on Microsoft Teams, be sure that you have committed and pushed your final changes to GitHub. Once your final changes have been pushed, create a pull request that seeks to merge the changes in your `develop` branch into your `trunk` branch. Once your pull request has been created, submit the URL of your assignment _repository_ (i.e., _not_ the URL of the pull request) as a Link Resource on Microsoft Teams. Please note: the timestamp of the submission on Microsoft Teams is used to assess any late penalties if and when warranted, _not_ the date/time you create your pull request. **No exceptions will be granted for this oversight**.


* After 48 hours, the assignment will not be graded and thus earns no points, i.e., 0 out of 3 possible points.
