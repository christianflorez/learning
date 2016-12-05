import random

handAi = ["Rock", "Paper", "Scissors"]

def thegame(userinput):
    """This is the main code for the game."""
    computerHand = random.choice(handAi)
    if userinput == "rock":
        print "The computer chooses " + str(computerHand.lower()) + "."
        if computerHand == "Rock":
            print "Tie!"
        elif computerHand == "Scissors":
            print "Rock smashes scissors, you win!"
        elif computerHand == "Paper":
            print "Paper covers rock, you lose!"
    elif userinput == "paper":
        print "The computer chooses " + str(computerHand.lower()) + "."
        if computerHand == "Rock":
            print "Paper covers rock, you win!"
        elif computerHand == "Scissors":
            print "Scissors cuts paper, you lose!"
        elif computerHand == "Paper":
            print "Tie!"
    elif userinput == "scissors":
        print "The computer chooses " + str(computerHand.lower()) + "."
        if computerHand == "Rock":
            print "Rock smashes scissors, you lose!"
        elif computerHand == "Scissors":
            print "Tie!"
        elif computerHand == "Paper":
            print "Scissors cuts paper, you win!"
    else:
        print "Try again!"


print "Let's Play!"
count = True
while count == True:
    userinput = raw_input("Rock, Paper, or Scissors? ")
    userinput = userinput.lower()
    if userinput == "exit":
        print "Thanks for playing!"
        break
    thegame(userinput)

