import subprocess
import re

def run_test(test_input, expected_output):
    print(f"Ejecutando TEST con entrada: {test_input}")
    
    # Ejecutar el programa pmerge y capturar la salida
    result = subprocess.run(
        ['./pmerge'] + test_input.split(),
        capture_output=True,
        text=True
    )
    
    # Capturar la salida del programa
    output = result.stdout.strip()
    
    # Capturar el error estándar si existe
    error_output = result.stderr.strip()
    
    # Mostrar la salida completa del programa para depuración
    print(f"Salida obtenida:\n{output}")
    print(f"Error obtenido:\n{error_output}")
    
    # Filtrar la salida para solo considerar las líneas relevantes
    relevant_output = "\n".join(line for line in output.splitlines() if "Before:" in line or "After:" in line or "Error" in line or "Empty string" in line)

    # Normalizar los tiempos y otros posibles valores cambiantes
    relevant_output = re.sub(r"Time to process with .+: \d+\.\d+ ms", "Time to process: <TIME>", relevant_output)
    
    # Comparar la salida esperada con la salida obtenida, normalizando el formato
    relevant_output = "\n".join(line.strip() for line in relevant_output.splitlines())
    expected_output = "\n".join(line.strip() for line in expected_output.splitlines())
    
    if relevant_output == expected_output:
        print("✔ Prueba exitosa")
    else:
        print("✖ Fallido")
        print(f"Salida esperada:\n{expected_output}")
        print(f"Salida obtenida:\n{relevant_output}")


# Definir las pruebas
run_test("5 3 8 6 2", "Before: 5 3 8 6 2\nAfter: 2 3 5 6 8")
run_test("10 20 30 40 50", "Before: 10 20 30 40 50\nAfter: 10 20 30 40 50")
run_test("1 2 2 3", "Error: Duplicate values are not allowed")
run_test("100", "Error: Only one element in the container")
run_test("", "Error: Empty string")
