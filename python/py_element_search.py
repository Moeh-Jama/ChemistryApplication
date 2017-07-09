import py_gather_elements as ge
def get_compound_properties(compound, array):
	print("Getting compound...")
	check_non_subscript = compound.isalpha()
	print("Subscript in element is: "+ str(check_non_subscript))
	number_of_elements = []
	i = 0
	save_index = 0;
	k=0
	subscript = 1
	for element in compound:
		subscript=1
		# Create a temporary list.
		save_element = []
		big_sub = []
		# Check if the letter is upper Cased.
		if compound[i].isupper():
			k=i+1
			save_element.append(compound[i])
			# While the consective letters are lower case we do as below.
			while k < len(compound):
				elem = compound[k]
				if elem.isupper():
					# If letter is uppercase then end loop.
					break;
				elif not elem.isalpha():
					big_sub.append(elem)
					#print(elem)
				else:
					# else add it to the array.
					save_element.append(elem)
				k=k+1

			if big_sub:
				subscript = int(''.join(big_sub))
			print("Subscript is: " + str(subscript))
			search_array(''.join(save_element), subscript, array)
			#print(compound[i])
		i+=1
		#print(save_element)
def search_array(element, subscript, array):
	print('Searching through array...')
	for index in array:
		if element == index['Symbol']:
			print("The Atomic Weight of "+index['Element']+" is "+str(index['Atomic_Weight'] * subscript)+"g mol-1")
