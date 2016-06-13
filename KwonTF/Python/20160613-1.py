import modHero

querySkill = input("Select Weapon : ")
i = 0
for each_item in modHero.skill:
    if(each_item == querySkill):
        modHero.printItem(querySkill, i)
    i = i+1

print("-----------------------------------------------\n")