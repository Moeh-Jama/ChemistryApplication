import tkinter as tk 
import jamastry_create_elements as jce
import jamastry_calculations as jcalc
import tkinter.messagebox

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
		jce.begin()
		jce.melting_stats()



class GetCompoundMixture(tk.Frame):

	def __init__(self, parent, controller):
		tk.Frame.__init__(self, parent)
		label = tk.Label(self, text="Combine Two Elements or Compounds!")
		label.pack(pady=12, padx=12)

		self.first_entry = tk.Entry(self)
		self.first_entry.pack(side="left")

		self.add_symbol = tk.Label(self, text=" + ")
		label.pack(pady=2, padx=3)
		self.second_entry = tk.Entry(self)
		self.second_entry.pack(side="left")

		self.button_one = tk.Button(self, text="Combine Both Elements", command=self.get_Result)
		self.button_one.pack()

		self.button_two = tk.Button(self, text="Back To Main Menu",
								command=lambda:controller.display_window(MainPage))
		self.button_two.pack()

	def get_Result(self):
		first_result = jcalc.get_compound_properties(str(self.first_entry.get()), jce.array)
		second_result = jcalc.get_compound_properties(str(self.second_entry.get()), jce.array)
		tota_result = first_result + second_result
		message = "The Total Atomic Weight of the Compound is "+str(tota_result)+" g mol"
		tkinter.messagebox.showinfo('stoichiometric calculation result', message)

def test_commands():
	print("Successful Click")


jce.begin()
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