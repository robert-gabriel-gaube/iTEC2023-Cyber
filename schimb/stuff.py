
negustor_stoc_nomisma = 10
negustor_stoc_solidus = 10
client_stoc_nomisma = 10
client_stoc_solidus = 10

suma = -19

x = negustor_stoc_nomisma
y = negustor_stoc_solidus
schimb = y - (x * y) // (x + suma)

negustor_stoc_nomisma += suma
negustor_stoc_solidus -= schimb 

client_stoc_nomisma -= suma
client_stoc_solidus += schimb 

for suma in range(0, 27):
    if(x + suma != 0):
        x = negustor_stoc_nomisma
        y = negustor_stoc_solidus
        schimb = y - (x * y) // (x + suma)
        print("NEGUSTOR:")
        print(negustor_stoc_nomisma + suma, negustor_stoc_solidus - schimb)
        print("CLIENT")
        print(client_stoc_nomisma - suma, client_stoc_solidus + schimb)
        if(client_stoc_nomisma - suma + client_stoc_solidus + schimb == 39):
            print("WOWOW SOlution")
        print("-----")
