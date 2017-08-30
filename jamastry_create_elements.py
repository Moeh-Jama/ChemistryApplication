import requests
periodic_table = {}

def create_periodic_table():
	# element_property is used to store the elements in the appropriate order.
	element_property={}
	# data is gathered from a JSON file on github.
	req_JSON_elements = requests.get('https://moeh-jama.github.io/periodic_table.json')
	# data are now sepereated and stored individually into ARRAY.
	# With appropriate data types implemented.
	for element in req_JSON_elements.json():
		element_property[element['Symbol']]={
		'Element': element['Element'],
		'Symbol': element['Symbol'],
		'Atomic_Number': float(element['Atomic_Number']),				
		'Atomic_Weight':float(element['Atomic_Weight']),
		'Elect_Aff': float(element['Ce']),			
		'Elect_Confg': element['Elect_Confg'],
		'Groups': int(element['Groups']),
		'layer': int(element['Layer']),			
		'mp': float(element['mp']),
		}
		# data stored in the dict element_property is now stored in
		# the array. 
		periodic_table[element['Symbol']] = (element_property[element['Symbol']])

"""
Temporarily Closed Deleted melting_stats().
"""
def quick_finder(Symbol, subscript):

	print('Quick Finder Engaged!', end=' |')
	print(Symbol)
	found = False
	if Symbol in periodic_table:
		print("The Atomic Weight of "+periodic_table[Symbol]['Element']+" is "+str(periodic_table[Symbol]['Atomic_Weight'] * subscript)+"g mol-1")
		return (periodic_table[Symbol]['Atomic_Weight']*subscript)
	elif found == False:
		print('Element is not present in the Periodic Table !')
		return -2017
