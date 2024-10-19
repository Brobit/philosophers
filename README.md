#Philosophers

##Suject

- the Philosophers alternatively eat, think, sleep;
they are doing one thing at a time, they can't do two
things in the same time
- there are fork on the table, as many as Philosophers
- it takes two forks to eat, one in each hand
- when stop eating, they sleep, then they think while
waiting to eat, he simulation stop when a philo die of starvation
- every philo need to eat and should never starve
- Philosophers don't speak
- Philosophers don't know if another philosopher is 
about to die
- Philosophers should avoid dying

##Global rules

- write a program
- no global variable (maybe use static)
- argument of the program

./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

number_of_philosophers : numer of philosophers and also the number of fork

time_to_die (in milliseconds) : if a philo didn't start eating at time_to_die
milliseconds since the beginning of their last meal or the beginning of the 
simulation, they die.

time_to_eat (in milliseconds) : the time it takes for a philo to eat, while 
they are eating they have two forks

time_to_sleep (in milliseconds) : the time a philo will spend sleeping

number_of_times_each_philosopher_must_eat (optional argument) : if all 
philo have eaten at least number_of_times_each_philosopher_must_eat times,
the simulation stop. If the argument isn't specified, the simulation 
continue until a philo die.

- each philo has a number ranging from 1 to number_of_philosophers
- philo number 1 sits next to philo number number_of_philosophers, any 
other philo number N sits between philo number N-1 & philo number N+1

##Logs of the program : 

- any state change of a philo must be formatted as follows:
    - timestamp_in_ms X has taken a fork
    - timestamp_in_ms X is eating
    - timestamp_in_ms X is sleeping
    - timestamp_in_ms X is thinking
    - timestamp_in_ms X died

replace timestamp_in_ms with the current timestamp in milliseconds
and X by the philo number

- a displayed message chould not be mixed up with another message
- a message announcing a philo died should be displayed no more than
10ms after the actual death of the philo

### The program should not have data races !!!

## mandatory part

- program name : philo
- turn in files : Makefile, *.h, *.c, in directory philo/
- Makefile : NAME, all, clean, fclean, re
- arguments : number_of_philosophers, time_to_die, time_to_eat
time_to_sleep [number_of_times_each_philosopher_must_eat]
- external function : 
    - [ ] memset
    - [ ] printf
    - [ ] malloc
    - [ ] free
    - [ ] write
    - [ ] usleep
    - [ ] gettimeofday
    - [ ] pthread_create
    - [ ] pthread_detach
    - [ ] pthread_join
    - [ ] pthread_mutex_init
    - [ ] pthread_mutex_destroy
    - [ ] pthread_mutex_lock
    - [ ] pthread_mutex_unlock

### specific rules

- each philo should be a thread
- there is one fork between each pair of philo. Therefore,
if there are several philos, each philo has a fork on their left side 
and a fork on their right side. If there is only one philo, there is
only one fork on the table
- to prevent philo from duplicating forks, you should protect the 
fork state with a mutex for each of them
