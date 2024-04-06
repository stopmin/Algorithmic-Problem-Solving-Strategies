import sys

while True:
  # 1. 온점 하나(.)가 들어오면 종료된다. (종료 조건) 
  str_data = sys.stdin.readline().rstrip()
  if str_data == ".":
    break

  # 2. 구현하기
  str_data = list(str_data)  # 입력 받은 문자열을 리스트로 변환
  bracket_lst = []  # 괄호를 담을 스택

  for word in str_data:
    # 열린 괄호는 스택에 쌓기
    if word == '(' or word == '[':  
      bracket_lst.append(word)
    # ★★ 닫힌 괄호는 괄호 스택의 값에 따라 분류됨
    elif word == ')':
      # 만약 짝이 맞다면 짝 맞춰 없앤다는 느낌으로 이전 열린 괄호를 pop해주기. 그렇지 않으면 균형 잡히지 못했으므로 반복문 멈추기
      if len(bracket_lst) != 0 and bracket_lst[-1] == '(':
        bracket_lst.pop()
      else:
        bracket_lst.append(word)
        break
    elif word == ']':
      if len(bracket_lst) != 0 and bracket_lst[-1] == '[':
        bracket_lst.pop()
      else:
        bracket_lst.append(word)
        break
        
  # 만약 괄호가 전부 짝지어져서 균형 잡혔다면 yes를 출력, 그렇지 않다면 no를 출력 
  if len(bracket_lst) == 0:
    print("yes")
  else:
    print("no")
