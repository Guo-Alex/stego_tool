function fea = read_fea(file_path)
% Reads *.fea file [file_path]
% returns structure [fea] which contains next fields:
%   F - array of features (row-by-row)
%   names - cell array of image file names which features represents in [F]
%
% === Description output [fea] structure:
%   If file fea contains features from [img_count] images 
%   with feature dimension [feature_dim]
%   then [F] is array with [img_count] rows and [feature_dim] columns
%   [names] is cell array with [img_count] elements
% === end 

% === Description input *.fea file structure:
%   Text file which contains [img_count] lines of features divided by '\n'
%   Each line represents feature of one image - feature is array of real values. 
%   The first [feature_dim] elements of line (divided by space) is feature's values
%   the last is string that represents image filename
% === end 
 
    fid = fopen(file_path);
    F = [];
    names = {};
    tline = fgetl(fid);
    idx = 1;
    while ischar(tline)
        [f, name] = parse_line(tline);        
        F = [F; f]; % add row
        names{idx} = name; % only if image names the same size
        tline = fgetl(fid);        
        idx = idx + 1;
    end

    fclose(fid);

    fea.F = F;
    fea.names = names;
end

function [F, name] parse_line(line) 
    feature_end_idx = -1;
    for idx=length(line):-1:1         
        if (line(idx)== ' ') 
            feature_end_idx = idx;
            break;  
        end; 
    end;

    if (feature_end_idx == -1)
        errorMessage = sprintf('Error: wrong fea file format: ', line);
        uiwait(warndlg(errorMessage));
    end
    name = line(feature_end_idx+1:length(name));
    F = str2num(line(1: feature_end_idx));
end