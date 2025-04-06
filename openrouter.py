import requests
import json
import sys
import re
def call_api(content):
    try:
        url = "https://api.siliconflow.cn/v1/chat/completions"

        payload = {
            "model": "THUDM/glm-4-9b-chat",
            "messages": [
                {
                    "role": "user",
                    "content": content
                }
            ],
            "stream": False,
            "max_tokens": 512,
            "stop": None,
            "temperature": 0.3,
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
            
        # 检查HTTP状态码
        response.raise_for_status()
        
        # 解析JSON数据
        result = response.json()
        
        # 提取模型返回内容
        if "choices" in result and len(result["choices"]) > 0:
            return result["choices"][0]["message"]["content"]
        else:
            return "ERROR: Invalid response format"
    except Exception as e:
        # 简化错误处理，任何错误都返回默认值
        print(f"API调用错误: {str(e)}")
        return "5"
    

if __name__ == "__main__":
    # 测试调用
  try:
    print("正在处理输入：")
    if(len(sys.argv)>2):
        string1 = sys.argv[1]
        string2 = sys.argv[2] 
        answer = call_api(f"按1到10给{string1}和{string2}的相似程度打分，直接返回数字")
        match = re.search(r'\b([1-9]|10)\b', answer)
        if match:
            answer = match.group(0)
        else:
            answer = "ERROR: Invalid response format"
    else:
       print("ERROR: Invalid input format")
       sys.exit(1)
   
    sys.stdout.write(answer)
    sys.stdout.flush()
  except Exception as e:
    sys.stdout.write(f"ERROR: {str(e)}")
    sys.stdout.flush()