main()
{
  *acc = ""
  *old_s = 0.0 ; *old_us = 0;
  if (0==msiget_precise_time( *acc,*old_s,*old_us,*s,*us )) {
    writeLine("stdout", "recorded start time")
  }
  *text = ""
  *acc2 = "0"
  for (*z=0;*z<10;*z=*z+1) { 
    msiSleep("0","50000")
    *old_s=*s ; *old_us=*us ;
    if (0==msiget_precise_time( *acc2,*old_s,*old_us,*s,*us )) {
      *text = "*text *acc2"
    }
  }
  writeLine("stdout" , "increments:" ++ *text)
}

INPUT null
OUTPUT ruleExecOut
