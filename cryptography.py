#Fatima Shibli
#project 2

#=================================================================================================================

import sys
#=================================================================================================================
# This function uses XOR to decrypt 

def dec(SPC, LTR):
    REF = list("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz") #this should be a list of all possible words

    for char in REF:
        if (ord(char)^32 == int(SPC,16)^int(LTR,16)):
            return char
        elif (int(SPC,16)^int(LTR,16) == 0):
            return " "

    return "_" # this output= something went wrong

#================================================================================================================
# Scans the crypted messages

def scanMSGS(cryptext):
    # Raw message stored 
    MSGS = []
    for i in range(0,len(cryptext)): 
        line = ["_"] * 60
        MSGS.append(line[:])

    # Bulk of the decrypting
    for i in range(0,120,2):
        SPCLoc = -1 # no SPC found

        # Two vars to be used in the case that the SPC is in the first message
        counter1 = 0
        counter2 = 0

        # XOR to check for values > 65
        for j in range(1, len(cryptext)):
            xor_val = int(cryptext[0][i:i+2],16) ^ int(cryptext[j][i:i+2],16)
            if xor_val >= 65: 
                SPCLoc = j
                counter2+=1
            elif xor_val == 0: # In case there are multiple SPCs in column
                counter1+=1

        # If  no SPC was found, loop back
        if SPCLoc == -1:
            continue

        # matches the number of of XOR above 65
        if (counter2 == (len(cryptext)-(1+counter1))):
            SPCLoc = 0

        # Location of SPC
        SPC = cryptext[SPCLoc][i:i+2]

        # returns to raw message list
        for j in range(0, len(cryptext)):
            MSGS[j][int(i/2)] = dec(SPC, cryptext[j][i:i+2])

    # Turns raw message into list of strings
    cmsgs = []
    for msg in MSGS:
        cmsgs.append("".join(msg))

    # Cleaned up
    cmsgs = '\n'.join(cmsgs)

    # Returns Cleaned MSGS
    return cmsgs[:]
#=====================================================================================================
# Main function 
def main():
 

    # Takes user input on name of file
    nameoffile = input("Please enter the name of the crypted file: ")

    # Catches nonexistant name of file
    try:
        with open(nameoffile, "r") as file: #close the open file 
            cryptext = file.read().splitlines()
    except FileNotFoundError:
        print("File doesn't exist")
        sys.exit()

    # Prints Decoded Message
    print("Plaintext messages:")

    decrypted_msgs = scanMSGS(cryptext)
    print(decrypted_msgs)

#================================================================================================================
#calling the main function 
if __name__ == "__main__":
    main()
else: 
    print("program can't run")
