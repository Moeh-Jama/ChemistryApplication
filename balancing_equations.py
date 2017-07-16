import jamastry_create_elements as jce


#current_elements in a given compound.
current_compound = []

def balance_front_end(compound_a, compound_b):
	""" Balance both compounds."""
	# import all Elements into an array
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
			first_current_comp = jce.return_element_name(current_compound[i])
			last_current_comp = jce.return_element_name(current_compound[j])

			# compare the element names symbols.
			if first_current_comp == last_current_comp:
				# get compound subscripts
				subscript_first = jce.return_element_digit(current_compound[i])
				subscript_last = jce.return_element_digit(current_compound[j])

				if int(subscript_last) != 0 or int(subscript_first) != 0:
					subscript += int(subscript_first) + int(subscript_last)
				if (subscript_last == 0) or (subscript_first ==0):
					count+= 1
				else:
					count = 0
				#print('count is currently: '+ str(count))
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
	string_result = ''
	i=0
	for element in current_compound:
		string_result +=element
		if(element != current_compound[-1]):
			string_result+='+'
		i+=1
	return string_result


def get_single_element(compound, options):
	print(compound)
	i = 0
	total_atomic_weight = 0
	while i < len(compound):
		string = ''
		if compound[i].isupper() and (i <= (len(compound))):
			k = i+1
			numbers = 0
			string += compound[i]
			while k < len(compound):
				comp = compound[k]
				if comp.isupper():
					# If letter is uppercase then end loop.
					break;
				elif not comp.isalpha():
					print(comp)
					numbers+=1
					#print(elem)
				else:
					# else add it to the array.
					string += comp
				k=k+1
		if(string != ''):
			new_string = compound[i:k-numbers]
			subscript = ''
			subscript = jce.return_element_digit(compound[i:k])
			if options ==1:
				if int(subscript) != 0:
					new_string +=str(subscript)
				current_compound.append(new_string)
			elif options == 2:
				total_atomic_weight = jce.search_array(new_string, int(subscript))
		i+=1
	return total_atomic_weight

#current_compound.append((compound[i] + comp))
"""hydrogen = 'He3Ag9Na7Cl5'
balance_front_end(hydrogen, 'MoHe9Na120Cl7Ag')"""