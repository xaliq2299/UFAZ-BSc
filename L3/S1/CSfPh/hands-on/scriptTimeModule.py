
import timeModule as tm

currentTime = tm.convertsec(17,30,0)
toLunch = tm.lunchTime - currentTime
toDinner = tm.dinnerTime - currentTime

h,m,s = tm.converthms(abs(toLunch))
print(tm.printTime(h, m, s), tm.beforeAfter(toLunch), 'lunch')
h,m,s = tm.converthms(abs(toDinner))
print(tm.printTime(h, m, s), tm.beforeAfter(toDinner), 'dinner')