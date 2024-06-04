import os
from openai import OpenAI
from dotenv import load_dotenv

# Load environment variables from the .env file
load_dotenv()

api_key = os.environ.get("OPENAI_API_KEY")
client = OpenAI(api_key=api_key)



def chat_with_gpt(prompt):
    response = client.chat.completions.create(model="gpt-3.5-turbo",
    messages=[{"role": "user", "content": prompt}])
    return response.choices[0].message.content.strip()

if __name__ == "__main__":
    while True:
        user_input = input("You: ")
        if user_input.lower() in ["bye", "goodbye"]:
            print("GPT-3: Goodbye!")
            break

        response = chat_with_gpt(user_input)
        print("GPT-3:", response)

print("It's working!")