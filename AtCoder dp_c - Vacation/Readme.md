$dpa[i] = max(dpb[i - 1], dpc[i - 1]) + a[i]$


$dpb[i] = max(dpa[i - 1], dpc[i - 1]) + b[i]$


$dpc[i] = max(dpa[i - 1], dpb[i - 1]) + c[i]$
