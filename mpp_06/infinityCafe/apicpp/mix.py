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
    substance1 = sys.argv[1]
    substance2 = sys.argv[2]
    print(generate_mixture_result(substance1, substance2))
