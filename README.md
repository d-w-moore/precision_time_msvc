
# precision_time_msvc

Definition
```

get_precise_time ( 

    *Accum,                    # string # (Input)  - empty or ASCII repr of double
                               # (Output) - seconds cumulative (integer + optional fraction)
                                                       
    *Old_sec, *Old_microsec,   # (double, int) # (Input) -  pair of old time values -beginning of interval
                   
    *new_sec, *new_microsec    # (double, int) # (Output) - pair of new time values - end of interval
)
```
See the `*.r` files in `./src` for demonstration.
