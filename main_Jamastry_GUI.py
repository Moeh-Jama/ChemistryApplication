import time
now = time.time()

import tkinter as tk 
last = time.time()
print('tkinter '+str(last-now)+'s')
from jamastry_create_elements import create_periodic_table
print('jce '+str(time.time() - last)+'s')
eff = time.time()
import balancing_equations as be
print('be '+str(time.time() - eff)+'s')
nower = time.time()
import tkinter.messagebox
print('msg '+str(time.time() - nower)+'s')
class BigBossGUI(tk.Tk):

	def __init__(self):
		tk.Tk.__init__(self)

		# Container
		container = tk.Frame(self)
		container.pack(side = "top", fill="both", expand=True)
		container.grid_rowconfigure(0, weight=1)
		container.grid_columnconfigure(0, weight=1)

		# Where the Frames will be stored and displayed when called for.
		self.frame_container = {}

		for window in (MainPage, Graphical, GetCompoundMixture):
			frame = window(container, self)
			self.frame_container[window] = frame
			frame.grid(row=0, column=0, sticky="nsew")
		self.display_window(MainPage)

	def display_window(self, cont):
		frame = self.frame_container[cont]
		# tkraise gets us to the next page (Raises the next Frame to display)
		frame.tkraise()

class MainPage(tk.Frame):

	def __init__(self, parent, controller):
		tk.Frame.__init__(self, parent)
		label = tk.Label(self, text="Welcome to Jamastry, the chemistry application")
		label.pack(pady=12, padx=12)

		# User option Prompts !

		button_one = tk.Button(self, text="Combine Compounds", command=lambda:controller.display_window(GetCompoundMixture))
		button_one.pack()

		button_two = tk.Button(self, text="Next Page", command=lambda:controller.display_window(Graphical))
		button_two.pack()

		

	def doNothing(self):
		print("Congrats you achieved nothing!")

class Graphical(tk.Frame):

	def __init__(self, parent, controller):
		tk.Frame.__init__(self, parent)
		label = tk.Label(self, text="Graphical Imagery")
		label.pack(pady=12, padx=12)

		# User is prompted to do something !
		button_one = tk.Button(self, text="Get Melting Point Graphs", command=self.get_graph)
		button_one.pack()

		button_two = tk.Button(self, text="Go Back to Main Menu", command=lambda:controller.display_window(MainPage))
		button_two.pack()

	def get_graph(self):
	#	melting_stats()
		print('Melting Stats')



class GetCompoundMixture(tk.Frame):

	def __init__(self, parent, controller):
		tk.Frame.__init__(self, parent)
		label = tk.Label(self, text="Combine Two Elements or Compounds!")
		label.pack(pady=12, padx=12)

		self.first_entry = tk.Entry(self)
		self.first_entry.pack()

		self.add_symbol = tk.Label(self, text=" + ")
		self.add_symbol.pack(pady=2, padx=3)

		self.second_entry = tk.Entry(self)
		self.second_entry.pack()

		self.button_one = tk.Button(self, text="Combine Both Elements", command=self.get_Result)
		self.button_one.pack()

		self.button_two = tk.Button(self, text="Back To Main Menu",
								command=lambda:controller.display_window(MainPage))
		self.button_two.pack()

	def get_Result(self):
		# Getting user inputs.
		right_now = time.time()
		first_compound = str(self.first_entry.get())
		last_compound = str(self.second_entry.get())
		# create one compound, balance it first.
		new_compound=''
		if first_compound == '':
			new_compound = be.balance_front_end('', last_compound)
		elif last_compound == '':
			new_compound = be.balance_front_end(first_compound, '')
		else:
			new_compound = be.balance_front_end(first_compound, last_compound)
		# get the atomic weight of the new single compound.
		total_Atomic_Weight = be.get_single_element(str(new_compound), 2)

		msg = "The Total Atomic Weight of the Compound is "+str(total_Atomic_Weight)+" g mol"

		get_name = 'The Total mass of the compound ' + str(new_compound) + ' is '+str(total_Atomic_Weight)+' g mol'
		self.new_Label = tk.Label(self, text=get_name)
		self.new_Label.pack()
		later_now = time.time()
		elapsed_now = later_now - right_now
		print('It took '+str(elapsed_now)+'s to compute this inquiry.')

def test_commands():
	print("Successful Click")


# Functions that must be created before the 
# GUI is created.

create_periodic_table()
done = time.time() - now
print("Elapsed time... %f seconds" % (done))


jamastry = BigBossGUI()
jamastry.title("Jamastry, Chemistry Application")
jamastry.minsize(width=400, height=400)
jamastry.maxsize(width=800, height=800)


menubar = tk.Menu(jamastry)
filemenu = tk.Menu(menubar)
filemenu.add_command(label="Start Again", command=test_commands)
filemenu.add_command(label="View Graphical Rep", command=test_commands)
filemenu.add_command(label="View Files", command=test_commands)
filemenu.add_command(label=" click me pls", command=test_commands)
filemenu.add_separator()
filemenu.add_command(label="Quit", command=jamastry.quit)
menubar.add_cascade(label="File", menu=filemenu)

jamastry.config(menu=menubar)
jamastry.mainloop()