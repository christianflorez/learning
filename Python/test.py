def saltytits(myname):
    myname = myname.lower()
    if myname == str("todd"):
        print ("Nice my dude man")
    elif myname == "turtle":
        print ("Bro no way, you're a fricking turtle? Nice dude...")
    elif len(myname) <= 0:
        print ("What's that bro? I couldn't hear ya...")
    else:
        print ("Nah dude, totes lame")
    return myname

print ("Sup Bro")
enteredname = input("Dude like, what's your name brah?")
saltytits(enteredname)
