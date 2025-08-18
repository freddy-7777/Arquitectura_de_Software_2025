import tkinter as tk
import requests

# Dirección IP de la ESP32
esp32_ip = "172.26.163.235"  # Asegúrate de que esté en la misma red

# Función para cerrar la ventana
def Close_Window():
    cuadro.destroy()

# Función para encender el LED
def Encender_Led():
    try:
        response = requests.get(f"http://{esp32_ip}/led/verde/on")
        print(response.text)
    except requests.exceptions.RequestException as e:
        print(f"Error: {e}")

# Función para apagar el LED
def Apagar_Led():
    try:
        response = requests.get(f"http://{esp32_ip}/led/verde/off")
        print(response.text)
    except requests.exceptions.RequestException as e:
        print(f"Error: {e}")


# Crear la ventana principal de la GUI
cuadro = tk.Tk()
cuadro.geometry("1500x700")
cuadro.title("Interfaz Gráfica del Semáforo")

# Frame superior
TitleFrame = tk.Frame(cuadro, bg="black", width=300, height=700)
TitleFrame.place(x=0, y=0)

# Frame inferior
ButtonsFrame = tk.Frame(cuadro, bg="blue", width=1200, height=700)
ButtonsFrame.place(x=160, y=0)

# Botones
button_on = tk.Button(TitleFrame, text="Encender", bg="green", fg="white", font=("Arial", 10), command=Encender_Led)
button_on.place(x=45, y=77)

button_off = tk.Button(TitleFrame, text="Apagar", bg="red", fg="white", font=("Arial", 10), command=Apagar_Led)
button_off.place(x=45, y=200)

button_close = tk.Button(TitleFrame, text="Cerrar", bg="gray", fg="black", font=("Arial", 10), command=Close_Window)
button_close.place(x=55, y=600)


# Iniciar la interfaz gráfica
cuadro.mainloop()