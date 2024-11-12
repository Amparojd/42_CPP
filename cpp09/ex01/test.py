import subprocess

# Colores para la salida
GREEN = '\033[92m'
RED = '\033[91m'
RESET = '\033[0m'

def run_test():
    tests = [
        {"input": ['3', '5', '+', '2', '*'], "expected_output": "16\n"},  # 3 + 5 = 8; 8 * 2 = 16
        {"input": ['9', '2', '-', '3', '/'], "expected_output": "2\n"},   # 9 - 2 = 8; 8 / 3 = 2
        {"input": ['2', '3', '*', '4', '+'], "expected_output": "10\n"},   # 2 * 3 = 6; 6 + 4 = 10
        {"input": ['5', '1', '2', '+', '4', '*', '+', '3', '-'], "expected_output": "14\n"}, # (1 + 2) * 4 + 5 - 3 = 14
        {"input": ['7', '3', '-', '4', '+'], "expected_output": "8\n"},    # 7 - 3 + 4 = 8
        {"input": ['2', '2', '2', '*', '+'], "expected_output": "6\n"},     # (2 * 2) + 2 = 6
        {"input": ['5', '2', '+', '3', '*'], "expected_output": "21\n"},    # (5 + 2) * 3 = 21
        {"input": ['9', '2', '/', '3', '4', '+', '-'], "expected_output": "-3\n"}, # (10 / 2) + (3 * 4) = 15
        {"input": ['10', '0', '/'], "expected_output": "Error: division by zero\n"},  # División por cero
    ]

    for idx, test in enumerate(tests, start=1):
        print(f"Ejecutando TEST {idx} con entrada: {' '.join(test['input'])}")  # Imprime la entrada
        try:
            result = subprocess.run(
                ['./rpn'] + test["input"],
                capture_output=True,
                text=True,
                check=True
            )
            if result.stdout == test["expected_output"]:
                print(f"{GREEN}✔ OK{RESET}")
            else:
                print(f"{RED}✖ Fallido{RESET}")
                print("Salida esperada:", test["expected_output"])
                print("Salida obtenida:", result.stdout)

        except subprocess.CalledProcessError as e:
            if "Error: division by zero" in test["expected_output"]:
                print(f"{GREEN}✔ OK (error manejado){RESET}")
            else:
                print(f"{RED}✖ Error al ejecutar el binario{RESET}")
                print("Salida de error:", e.stderr)

if __name__ == "__main__":
    run_test()
