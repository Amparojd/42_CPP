import subprocess
import re

def run_test(test_input, expected_output):
    print(f"Ejecutando TEST con entrada: {test_input}")
    
    # Ejecutar el programa pmerge y capturar la salida
    result = subprocess.run(
        ['./PmergeMe'] + test_input.split(),
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
    relevant_output_lines = sorted([line.strip() for line in relevant_output.splitlines()])
    expected_output_lines = sorted([line.strip() for line in expected_output.splitlines()])

    # Muestra solo los números y el tiempo de ejecución
    print(f"Salida obtenida:\n{relevant_output}")

# Definir las pruebas
run_test("50 34 23 5 12 7 8 3 18 40 19 21 2 36 26 4 10 11 1 28 15 6 14 29 22 35 20 38 33 17 30 9 31 32 27 16 39 25 13 24 37 41 43 45 46 47 42 48 44", 
         "Before: 50 34 23 5 12 7 8 3 18 40 19 21 2 36 26 4 10 11 1 28 15 6 14 29 22 35 20 38 33 17 30 9 31 32 27 16 39 25 13 24 37 41 43 45 46 47 42 48 44\nAfter: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48\nTime to process with std::vector: 6.098 ms\nTime to process with std::deque: 3.04 ms")

run_test("200 105 203 114 83 188 112 131 99 179 91 42 104 174 38 67 67 36 29 170 22 104 94 118 61 60 117 97 92 92 48 6 153 153 148 118 72 26 171 71 149 65 23 68 142 44 137 117 43 126 11 129 119 122 165 147 22 27 176 9 107 90 83 87 108 100 98 69 141 143 152 177 40 133 123 81 37 168 45 170 170 68 75 136 117 88 40 92 176 5 96 113 161 45 54 98 80 174 134 21 27 108 48 140 153 117",
         "Before: 200 105 203 114 83 188 112 131 99 179 91 42 104 174 38 67 67 36 29 170 22 104 94 118 61 60 117 97 92 92 48 6 153 153 148 118 72 26 171 71 149 65 23 68 142 44 137 117 43 126 11 129 119 122 165 147 22 27 176 9 107 90 83 87 108 100 98 69 141 143 152 177 40 133 123 81 37 168 45 170 170 68 75 136 117 88 40 92 176 5 96 113 161 45 54 98 80 174 134 21 27 108 48 140 153 117\nAfter: 5 6 9 11 21 22 22 23 26 27 27 29 36 37 38 40 40 42 43 44 45 45 48 48 54 60 61 65 67 67 68 68 69 71 72 75 80 81 83 83 87 88 90 91 92 92 92 94 96 98 99 100 104 104 105 107 108 108 112 113 114 117 117 117 117 118 118 119 122 123 126 129 133 134 136 137 140 141 142 143 147 148 149 152 153 153 161 165 168 170 170 170 171 174 174 176 176 177 179 188 200 203\nTime to process with std::vector: 15.097 ms\nTime to process with std::deque: 9.322 ms")

run_test("", "Error: Empty string\nUsage: ./PmergeMe [positive integer sequence]")
