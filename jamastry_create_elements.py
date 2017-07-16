import jamastry_calculations as es
#import graphical_user_interface as gui
import matplotlib.pyplot as plt 
import requests

array = []
def create_array():
	# element_property is used to store the elements in the appropriate order.
	element_property={}
	# data is gathered from a JSON file on github.
	req_JSON_elements = requests.get('https://moeh-jama.github.io/periodic_table.json')
	# data are now sepereated and stored individually into ARRAY.
	# With appropriate data types implemented.
	for element in req_JSON_elements.json():
		element_property[element['Atomic_Number']]={
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
		# array. 
		array.append(element_property[element['Atomic_Number']])

def begin():
	""" Called from Tkinter in order to set up the array,
						with the appropriate data
	"""
	create_array()

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

def melting_stats():
	"""
		Used in getting visual statistical information for the 
		GUI side of the app. 
	"""	
	# used as the X and Y axises for plotting of the 
	# melting point figure.
	X_train = []
	Y_train = []

	for melt in array:
		# Y axis is the melting point and X axis is the Group, (1-18)
		Y_train.append(float(melt['mp']))
		X_train.append(float(melt['Groups']))

	# figure is now created.
	plt.figure()
	plt.ylabel("Melting Point (Celsius)")
	plt.xlabel("Group")
	plt.scatter(X_train[:], Y_train[:], s=170, color="green")
	plt.show()

def search_array(element, subscript):
	""" Search through Array for element """
	print('Searching through array...')
	found = False
	for index in array:
		if element == index['Symbol']:
			found = True
			print("The Atomic Weight of "+index['Element']+" is "+str(index['Atomic_Weight'] * subscript)+"g mol-1")
			return (index['Atomic_Weight']*subscript)
	if found == False:
		print('Element is not present in the Periodic Table !')
		return -2017
