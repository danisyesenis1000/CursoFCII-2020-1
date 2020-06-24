
# Código de Python para fractal de Julia 
from PIL import Image 
   
# función del conductor
if __name__ == "__main__": 
    
    # Establecer el ancho, la altura 
    #y el zoom de la imagen que se creará 
    a, h, zoom = 1920,1080,1
   
    # creando la nueva imagen en modo RGB
    bitmap = Image.new("RGB", (a, h), "white") 
  
    # Asignando el almacenamiento 
    #para la imagen y cargando los datos de píxeles.  
    pix = bitmap.load() 
     
    # configurar las variables de acuerdo con 
    #la ecuación para crear el fractal 
    cX, cY =  -0.8, 0
    moveX, moveY = 0.0, 0.0
    maxIter = 255
   #Desplazamiento dentro del plano complejo bajo los conjuntos de Julia 
    for x in range(a): 
        for y in range(h): 
            #coordenadas  en la region compleja donde se establece imaginaria para zy y real para zx
            zx = 1.5*(x - a/2)/(0.5*zoom*a) + moveX 
            zy = 1.0*(y - h/2)/(0.5*zoom*h) + moveY 
            i = maxIter
            
            #aplicando sucesion para conjuntos de Julia con   el c dado 
            while zx*zx + zy*zy < 4 and i > 1: 
                tmp = zx*zx - zy*zy + cX #aplicacion 
                zy,zx = 2.0*zx*zy + cY, tmp 
                i -= 1
  
            #convierte byte a RGB (3 bytes), 
            #algo mágico para obtener colores agradables
            
            pix[x,y] = (i << 21) + (i << 10) + i*8
  
    
    # para mostrar el fractal creado 
    bitmap.show()
