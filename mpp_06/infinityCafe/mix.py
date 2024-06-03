import os
from openai import OpenAI
from dotenv import load_dotenv

load_dotenv()


api_key = os.environ.get("OPENAI_API_KEY")
client = OpenAI(api_key=api_key)

def generate_mixture_result(substance1, substance2):
    # Формуємо запит до моделі GPT-3.5-turbo-instruct
    prompt = f"Ти є розумною системою дегустатором, яка знає всі можливі результати змішування речовин.Відповідай лише назвою результуючої суміші.  Що буде, якщо змішати {substance1} і {substance2}, назва результуючої суміші буде:"

    response = client.completions.create(model="gpt-3.5-turbo-instruct",
    prompt=prompt,
    max_tokens=50)

    # Отримуємо текст з відповіді
    result = response.choices[0].text.strip()

    return result

# Створюємо список для зберігання результатів змішування
mixture_results = []

# Змішуємо різні речовини і додаємо результати до списку
mixture_results.append(generate_mixture_result("молоко", "кава"))
mixture_results.append(generate_mixture_result("вода", "лимон"))
mixture_results.append(generate_mixture_result("цукор", "вода"))
mixture_results.append(generate_mixture_result("молоко", "какао"))
mixture_results.append(generate_mixture_result("експрессо", "молоко"))
mixture_results.append(generate_mixture_result("цемент", "вода"))

# Виводимо результати
print(mixture_results)
