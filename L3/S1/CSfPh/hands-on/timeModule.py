

def convertsec(h,m,s):
    return s+m*60+h*3600
    
def converthms(sec):
    h = sec//3600
    m = (sec-h*3600)//60
    s = sec%60
    return h, m, s
    
def beforeAfter(sec):
    if sec<0:
        return 'after'
    else:
        return 'before'
        
def printTime(h,m,s):
    return str(h) + ' : ' + str(m) + ' : ' + str(s)

lunchTime = 12*3600
dinnerTime = 19*3600
    
    
    

            