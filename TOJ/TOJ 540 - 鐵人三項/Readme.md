$dpa[i] = dpa[i - 1] + a[i]$

$dpb[i] = min(dpa[i - 1], dpb[i - 1]) + b[i]$

$dpc[i] = min(dpb[i - 1], dpc[i - 1]) + c[i]$
