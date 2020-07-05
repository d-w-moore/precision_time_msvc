main()
{
  *s1 = ""
  *i = 0.0; *j = 0
  if (0==msiget_precise_time( *s1,*i,*j,*k,*l )) {
   #writeLine("stdout", "sec\tsuccess")
    writeLine("stdout", "sec\t*s1")
    writeLine("stdout", "usec\t*l");
  }
  #msiSleep("0","999000")
  *i = *k; *j = *l; *accum="0"
  if (0==msiget_precise_time( *accum,*i,*j,*k,*l )) {
    *a = *accum
  }
  msiSleep("1","495000")
  if (0==msiget_precise_time( *accum,*k,*l,*m,*n )) {
    writeLine("stdout", "total elapsed time = [*accum] secs")
  }
  writeLine("stdout" , " 1st accum = " ++  *a)
  writeLine("stdout" , "      diff = " ++  str(double(*accum) - double(*a)))
}

INPUT null
OUTPUT ruleExecOut
