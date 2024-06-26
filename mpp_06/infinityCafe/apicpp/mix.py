import os
from openai import OpenAI
from dotenv import load_dotenv
import sys

load_dotenv()


api_key = os.environ.get("OPENAI_API_KEY")
client = OpenAI(api_key=api_key)

def generate_mixture_result(substance1, substance2):
    # Формуємо запит до моделі GPT-3.5-turbo-instruct
    prompt = f"Ти є розумною системою дегустатором, яка знає всі можливі результати змішування речовин. Відповідай лише назвою результуючої суміші, без додаткових символів, точок і зайвих слів. Що буде, якщо змішати {substance1} і {substance2}, назва результуючої суміші буде:"

    response = client.completions.create(model="gpt-3.5-turbo-instruct",
    prompt=prompt,
    max_tokens=50)

    # Отримуємо текст з відповіді
    result = response.choices[0].text.strip()

    return result

if __name__ == "__main__":
    if len(sys.argv) < 3:
        print("Error: Not enough arguments provided.")
        sys.exit(1)
    substance1 = sys.argv[1]
    substance2 = sys.argv[2]
    print(generate_mixture_result(substance1, substance2))


'''
# Створюємо список для зберігання результатів змішування , тестуєм в mix.py
mixture_results = []

# Змішуємо різні речовини і додаємо результати до списку
mixture_results.append(generate_mixture_result("яблуко", "вода"))
mixture_results.append(generate_mixture_result("вода", "борошно))"))
mixture_results.append(generate_mixture_result("вода", "лимон"))
mixture_results.append(generate_mixture_result("цукор", "вода"))
mixture_results.append(generate_mixture_result("молоко", "какао"))
mixture_results.append(generate_mixture_result("експрессо", "молоко"))
mixture_results.append(generate_mixture_result("цемент", "вода"))

# Виводимо результати
print(mixture_results)
'''
