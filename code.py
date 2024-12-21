from PIL import Image
import math

def is_pixel_in_circle(x, y, center_x, center_y, radius):
    return (x - center_x)  2 + (y - center_y)  2 <= radius ** 2

def process_image(image_path):
    
   
    img = Image.open(image_path)  
    
    img = img.convert('L') 

    
    question_height = img.height // 4  
    option_width = img.width // 4  

    
    dark_pixel_threshold = 255  
    

    results = {q + 1: '' for q in range(4)}

    for q in range(4):
        correct_option = None  
        max_black_pixels = 0   
        option_count = 0       
        

        for o in range(4):
            
            left = o * option_width
            upper = q * question_height
            right = left + option_width
            lower = upper + question_height

            option_region = img.crop((left, upper, right, lower))

            radius = 15  
            center_x = (50 + (o * 8))  
            center_y = (50 + (q * 8)) 

            black_pixel_count = 0
            total_pixel_count = 0

            for x in range(option_width):
                for y in range(question_height):
                    if is_pixel_in_circle(x, y, center_x, center_y, radius):
                        total_pixel_count += 1
                        if option_region.getpixel((x, y)) < dark_pixel_threshold:
                            black_pixel_count += 1

            fill_percentage = (black_pixel_count / total_pixel_count) * 100 if total_pixel_count > 0 else 0

              

            if fill_percentage > 70:
                option_count += 1
                res = chr(ord('A') + o)
                results[q + 1] = res
        
        if option_count > 2:
            results[q + 1] = ''

    return results

def main():
    image_path = input()
    
 
    ans = list(map(str,input().split()))

   
    results = process_image(image_path)
    
  
    score = 0
    for i in range(4):
       
        if results[i + 1] == ans[i]:
            score += 1

    print(score)

if name == 'main':
    main()