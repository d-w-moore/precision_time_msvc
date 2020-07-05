main()
{
  *s1 = ""
  *i = 0.0; *j = 0
  if (0==msiget_precise_time( *s1,*i,*j,*k,*l )) {
    writeLine("stdout", "recorded start time")
  }
  *t = ""
  *s2 = "0"
  for (*z=0;*z<10;*z=*z+1) { 
    msiSleep("0","50000")
    *i=*k; *j=*l
    if (0==msiget_precise_time( *s2,*i,*j,*k,*l )) {
      *t = "*t *s2"
    }
  }
  writeLine("stdout" , "increments:" ++ *t)
}

INPUT null
OUTPUT ruleExecOut
