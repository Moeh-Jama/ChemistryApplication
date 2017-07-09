import py_element_search as es

element_property={}
array = []
def create_array():
	#filename stores the directory of the datasheet.
	filename = "properties_of_elements.txt"
	with open(filename, "r") as file_object:
		#break datasheet into lines, breaking at '\n'
		lines = file_object
		for line in lines:
			#in each line split them by their spaces. i.e. [mohamed 21] is then ['mohamed' '21']
			take = line.split()
			# once split we then put them in the dictionary structure as shown below.
			element_property[take[4]]={
				'Element': take[2],
				'Symbol': take[3],
				'Atomic_Number': float(take[4]),				
				'Atomic_Weight':float(take[5]),
				'Elect_Aff': take[8],			
				'Elect_Confg': take[6],
				'Groups': int(take[0]),
				'layer': int(take[1]),			
				'mp': float(take[7]),
			}
			# add element into the periodic array storeage.
			array.append(element_property[take[4]])

def main():
	create_array()
	user_active = True
	while user_active == True:
		print("Choose one of the following: \n");
		print("\t1.Combine two elements.\n");
		print("\t2.Print Periodic Table.\n");
		print("\t3.Sort Periodic listing.\n");
		print("\t4.Enter some element.\n");
		print("\t5.Exit\n");
		user_input = input("Enter: ")
		
		if int(user_input) ==1:
			combine_elements()
		elif int(user_input) ==2:
			print("Sorry not bothered!")
		elif int(user_input) == 3:
			print("Sorry not bothered!")
		elif int(user_input) == 4:
			compound = input("Enter compound: ")
			es.get_compound_properties(compound, array)
		elif int(user_input) == 5:
			print("Goodybye")
			user_active = False

if __name__ == "__main__":
	main()