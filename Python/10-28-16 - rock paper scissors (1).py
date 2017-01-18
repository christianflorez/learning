import random

handAi = ["Rock", "Paper", "Scissors"]

def thegame(userinput):
    """This is the main code for the game."""
    computer_hand = random.choice(handAi)
    if userinput == "rock":
        print "The computer chooses " + str(computer_hand.lower()) + "."
        if computer_hand == "Rock":
            print "Tie!"
        elif computer_hand == "Scissors":
            print "Rock smashes scissors, you win!"
        elif computer_hand == "Paper":
            print "Paper covers rock, you lose!"
    elif userinput == "paper":
        print "The computer chooses " + str(computer_hand.lower()) + "."
        if computer_hand == "Rock":
            print "Paper covers rock, you win!"
        elif computer_hand == "Scissors":
            print "Scissors cuts paper, you lose!"
        elif computer_hand == "Paper":
            print "Tie!"
    elif userinput == "scissors":
        print "The computer chooses " + str(computer_hand.lower()) + "."
        if computer_hand == "Rock":
            print "Rock smashes scissors, you lose!"
        elif computer_hand == "Scissors":
            print "Tie!"
        elif computer_hand == "Paper":
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

