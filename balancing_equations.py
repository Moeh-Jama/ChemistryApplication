from jamastry_create_elements import quick_finder
current_compound = []
def balance_front_end(compound_a, compound_b):
	""" Balance both compounds."""
	print("Balance front end....")
	# import all Elements into an current_compund array.
	get_single_element(compound_a, 1)
	get_single_element(compound_b, 1)

	""" Searching for duplicate elements in the array """
	i = 0
	while i < len(current_compound):
		# Binary Search.
		j=i+1
		subscript = 0
		while j < len(current_compound):
			count = 0
			subscript_first = 0
			subscript_last = 0
			# get compound, names only.
			first_current_comp = return_element_name(current_compound[i])
			last_current_comp = return_element_name(current_compound[j])

			# compare the element names symbols.
			if first_current_comp == last_current_comp:
				# get compound subscripts
				print("Found first and second comp.")
				subscript_first = return_element_digit(current_compound[i])
				subscript_last = return_element_digit(current_compound[j])
				# if a subscript is single add 1 to the count.
				if int(subscript_first) ==0:
					count+=1
				if int(subscript_last) == 0:
					count+=1
				if int(subscript_last) != 0 or int(subscript_first) != 0:
					subscript += int(subscript_first) + int(subscript_last)
					count += 0
				current_compound[i] = first_current_comp
				current_compound.pop(j)
			j+=1
		subscript += count

		if(subscript>0):
			current_compound[i] += str(subscript)
		i+=1
	print("Here is the Array of elements: "+str(current_compound))

	string_result = print_element(current_compound)
	print(string_result)
	return current_compound

def print_element(current_compound):
	""" Print the resulting combination """
	string_result = ''
	i=0
	for element in current_compound:
		string_result +=element
		if(element != current_compound[-1]):
			string_result+='+'
		i+=1
	return string_result


def get_single_element(compound, options):
	""" This Function divides a compound to its simplist elements.
		i.e. CAgCl is now ['C', 'Ag', 'Cl']
	"""
	print("Get single element....")
	print(compound)
	i = 0
	total_atomic_weight = 0
	while i < len(compound):
		string = ''
		if compound[i].isupper() and (i <= (len(compound))):
			# There character is uppecase, therefore the beginning of
			# A new element.
			k = i+1
			numbers = 0
			string += compound[i]
			while k < len(compound):
				comp = compound[k]
				if comp.isupper():
					# If letter is uppercase then end loop.
					break;
				elif not comp.isalpha():
					numbers+=1
				else:
					# else add it to the array.
					string += comp
				k=k+1
		if(string != ''):
			# once we have a elment we do the following computations.
			new_string = compound[i:k-numbers]
			subscript = ''
			subscript = return_element_digit(compound[i:k])
			if options ==1:
				print('option 1')
				if int(subscript) != 0:
					new_string +=str(subscript)
				current_compound.append(new_string)
			elif options == 2:
				print('option 2')
				if int(subscript) == 0:
					# so the atomic weight is not 0.
					subscript = '1'
				total_atomic_weight += quick_finder(new_string, int(subscript))
		i+=1
	return total_atomic_weight

def return_element_name(compound):
	""" Gets rid of subscripts in a compound
		for example H2 is turned to H.	"""
	no_subscript = ''.join([i for i in compound if not i.isdigit()])

	return no_subscript
def return_element_digit(compound):
	""" Only keeps the Subscripts in a compound
		for example H2 is turned to 2 """
	subscript = ''.join([i for i in compound if i.isdigit()])
	if(subscript == ''):
		return 0
	else:
		return subscript

