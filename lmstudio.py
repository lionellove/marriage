import requests
import json


url = "https://api.siliconflow.cn/v1/chat/completions"

payload = {
    "model": "THUDM/glm-4-9b-chat",
    "messages": [
        {
            "role": "user",
            "content": "按1到10分给basketball和football的相似程度打分，直接返回数字"
        }
    ],
    "stream": False,
    "max_tokens": 512,
    "stop": None,
    "temperature": 0.7,
    "top_p": 0.7,
    "top_k": 50,
    "frequency_penalty": 0.5,
    "n": 1,
    "response_format": {"type": "text"},
    "tools": [
        {
            "type": "function",
            "function": {
                "description": "<string>",
                "name": "<string>",
                "parameters": {},
                "strict": False
            }
        }
    ]
}
headers = {
    "Authorization": "Bearer sk-ertpnirztciunaozcaspcsrbmeeddzfapmykvckkpjuouxfc",
    "Content-Type": "application/json"
}

response = requests.request("POST", url, json=payload, headers=headers)
result = response.json()
if "choices" in result and len(result["choices"]) > 0:
    print(result["choices"][0]["message"]["content"])
