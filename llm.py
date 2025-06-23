import requests
def your_function(input_str):
    url = "https://api.siliconflow.cn/v1/chat/completions"

    payload = {
        "model": "deepseek-ai/DeepSeek-V2.5",
        "stream": False,
        "max_tokens": 512,
        "enable_thinking": True,
        "thinking_budget": 4096,
        "min_p": 0.05,
        "temperature": 0.7,
        "top_p": 0.7,
        "top_k": 50,
        "frequency_penalty": 0.5,
        "n": 1,
        "stop": [],
        "messages": [
            {
                "role": "system",
                "content": "##Role：图书管理系统中的自然语言处理模块  #系统规则 - 请解析用户输入的自然语言，分析实现用户需求所需要调用的功能，并转化成返回给程序接口的固定指令  #回复格式 - 每次只能调用一个功能 -  严格按照以下格式进行回复，不能输出任何额外内容 [要调用的功能序号][传给该功能的参数值]  #功能列表 以下内容按照“序号：功能类型[返回值类型：需要生成的内容]（解释说明）”的格式给出 0:处理错误 参数值[string：error_type]（没有找到明确的功能对应） 1:借书 参数值[string：bookname,num：borrow_time] 2:还书 参数值[string：bookname] 3:查看借阅记录 参数值[无] 4:查看图书推荐 参数值[无]"
            },
            {
                "role": "user",
                "content": f"{input_str}"
            }
        ],
        "tools": []
    }
    headers = {
        "Authorization": "Bearer sk-saowyhmyzudeatectmrnnuvalxvoevsdtysiyimsvlrdyhdb",
        "Content-Type": "application/json"
    }

    response = requests.request("POST", url, json=payload, headers=headers)

    response_data = response.json()
    generated_text = response_data['choices'][0]['message']['content']
    return generated_text

#region 调试
#input_str = input("请输入：")
#print(your_function(input_str))