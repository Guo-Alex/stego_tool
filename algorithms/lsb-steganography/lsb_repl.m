function S = lsb_repl(I, M, P)
% LSB Replacement
% I - color image with size =  w * h * 3;
% M - message to embed
% P - positions where embed message
% length(M) = length(P) < size(I)

    w = length(I);
    
    for i=1:length(P)
        [ic, jc, ch] = get_3d_position(P(i));        
        lsb = mod(I(ic, jc, ch), 2);
        I(ic, jc, ch) = I(ic, jc, ch) - lsb + M(i); 
    end
    
    S = I;
end

function [ic, jc, channel] = get_3d_position(position) 
    % get channel number
    channel = mod(position, 3); % 1,2,0
    % replace 0 on 3
    if channel == 0
        channel = 3;
    end 
    %get pixel number
    pixel_number = floor ( (position - 1) / 3) + 1; 
    %get pixel (i,j) coordinates
    ic = floor(pixel_number / width) + 1;
    jc = pixel_number - (ic - 1) * width;  
end







