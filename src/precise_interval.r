main()
{
  *accum = ""
  *old_s = 0.0; *old_us = 0
  if (0==msiget_precise_time( *accum,*old_s,*old_us,*s,*us )) {
    writeLine("stdout", "sec\t*accum")
    writeLine("stdout", "usec\t*us");
  }

  *old_s = *s; *old_us = *us; *accum="0"

  msiSleep("0","999000")

  if (0==msiget_precise_time( *accum,*old_s,*old_us,*s,*us )) {
    *save_accum = *accum
    writeLine("stdout", "new accum value '*accum'")
  }
  else { fail  }

  msiSleep("1","495000")

  if (0==msiget_precise_time( *accum,*s,*us,*m,*n )) {
    writeLine("stdout", "total elapsed time = [*accum] secs")
  }

  writeLine("stdout" , " 1st accum = " ++  *save_accum)

  writeLine("stdout" , "      diff = " ++  str(double(*accum) - double(*save_accum)))
}

INPUT null
OUTPUT ruleExecOut
