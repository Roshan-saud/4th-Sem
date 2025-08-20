'''
Lab 1 (Python): Reflex-based Intelligent Agent
Objective:
To design and implement reflex-based intelligent agents that make real-time 
decisions based on percepts from dynamic environments, such as traffic flow 
and presence detection. To simulate environment-agent interaction using Python,
demonstrating how agents can control systems like traffic signals and smart 
home lighting based on simple condition action rules.
'''

import random
import time

##case 1: Traffic light control Agent 
class TrafficEnvironment:
    #constructor to initialize the traffic light state
    def __init__(self): 
        self.traffic_density = "low"
        self.timer = 0
        self.light = "Red"

    def get_percept(self):
        return self.traffic_density, self.timer, self.light
    
    def update_environment(self):
        self.traffic_density = random.choice(["low","High"])
        self.timer+=1

    def execute_action(self, action):
        if action=="SwitchToGreen":
            self.light = "Green"
            self.timer = 0
            print("Action: light switch to Green")
        elif action == "SwitchToRed":
            self.light = "Red"
            self.timer = 1000
            print("Action: light switch to Red")
        else:
            self.light = "Yellow"
            self.timer = 100
            print("Action: Light switch to Yellow")

class TrafficLightAgent:
    def decide(self, traffic_density, timer, current_light):
        if current_light == "Red" and traffic_density == "High":
            return "SwitchToGreen"
        elif current_light == "Green" and traffic_density == "low":
            return "SwitchToRed"
        else:
            return "Yellow light Get Ready"
        


##case 2: Smart light Automation
class RoomEnvironment:
    def __init__(self):
        self.presence = False
        self.time = "Day"
        self.light = "OFF"

    def get_percept(self):
        return self.presence, self.time, self.light

    def update_environment(self):
        self.get_persence = random.choice(["True", "False"])
        self.time = random.choice(["Day", "Night"])
    
    def execute_action(self, action):
        if action == "TrunOn":
            self.light == "ON"
            print("Action: light truned ON")
        elif action == "TurnOff":
            self.light = "OFF"
            print("Action: light turned OFF")
        else:
            print("Action: No changes")

class SmartlightAgent:
    def decide(self, presence, time_of_day, current_light):
        if presence == "True" and time_of_day == "Night":
            return "TrunOn"
        elif presence == "False" and time_of_day=="Day":
            return "TurnOn"
        else:
            return "No Changes"
    
    #Simulation
def simulate_traffic_agent(steps):
        print("\n\n---- Traffic light agent simulation --- ")
        env = TrafficEnvironment()
        agent = TrafficLightAgent()
        for step in range(steps):
            #String interpolation : f string 
            print(f"\n [Steps: {step+ 1} ]")
            env.update_environment()
            percepts = env.get_percept()
            print(f"Percepts: Traffic Density {percepts[0]}, Timer ({percepts[1]}), light  {percepts[2]}")
            action = agent.decide(*percepts)
            env.execute_action(action)
            time.sleep(1)
    
def simulate_smart_light_agent(steps):
        print("\n--- Smart light agent ---")
        env = RoomEnvironment()
        agent = SmartlightAgent()

        for step in range(steps):
            print(f"\n Step: {step+1}")
            env.update_environment()
            percepts = env.get_percept()
            print(f"\n Percepts presence = {percepts[0]}, Time={percepts[1]}, light={[percepts[2]]}")
            action = agent.decide(*percepts)
            env.execute_action(action)
            time.sleep(1)

        

if __name__ == "__main__":
    simulate_traffic_agent(steps=5)
    simulate_smart_light_agent(steps=5)
